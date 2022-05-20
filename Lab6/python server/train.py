''' import numpy as np
import pandas
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Input
from keras.wrappers.scikit_learn import KerasClassifier
from keras.utils import np_utils
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold
from sklearn.preprocessing import LabelEncoder
from sklearn.pipeline import Pipeline

df = pandas.read_json('json_data.json')
# replace nan with -1000
df.fillna(0, inplace=True)
dataset = df.values
X = dataset[:, df.columns != 'location'].astype(float)
# multiple all values by -1
X[:, :] = X[:, :] * -1/100
Y = dataset[:, df.columns == 'location']

encoder = LabelEncoder()
encoder.fit(Y)
encoded_Y = encoder.transform(Y)
# convert integers to dummy variables (i.e. one hot encoded)
dummy_y = np_utils.to_categorical(encoded_Y)
print(dummy_y)

print(X)

# define baseline model


def create_model():
    # create model
    model = Sequential()
    model.add(Input(shape=np.shape(X[0]), name='input'))
    model.add(Dense(10, activation='relu'))
    model.add(Dense(10, activation='relu'))
    model.add(Dense(2, activation='softmax'))
    # Compile model
    model.compile(loss='categorical_crossentropy',
                  optimizer='rmsprop', metrics=['accuracy'])
    return model


model = create_model()
history_callback = model.fit(X, dummy_y, epochs=100, batch_size=50)
score = model.evaluate(X, dummy_y, verbose=0)
print('Test loss:', score[0])
print('Test accuracy:', score[1])
y_pred = model.predict(X)
actual = np.argmax(dummy_y, axis=1)
predicted = np.argmax(y_pred, axis=1)
print(actual)
print(predicted)
# save the model to disk
model.save('model.h5')
 '''

import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import tensorflow as tf

df = pd.read_csv('data_file.csv')
df.fillna(0, inplace=True)

df['is_inside'] = [
    1 if typ == 'inside' else 0 for typ in df['location']
]
df.drop('location', axis=1, inplace=True)

X = df.drop('is_inside', axis=1)
y = df['is_inside']

X_train, X_test, y_train, y_test = train_test_split(
    X, y,
    test_size=0.2, random_state=42
)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)


tf.random.set_seed(42)


model = tf.keras.Sequential([
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dense(256, activation='relu'),
    tf.keras.layers.Dense(256, activation='relu'),
    tf.keras.layers.Dense(1, activation='sigmoid')
])

model.compile(
    loss=tf.keras.losses.binary_crossentropy,
    optimizer=tf.keras.optimizers.Adam(lr=0.03),
    metrics=[
        tf.keras.metrics.BinaryAccuracy(name='accuracy'),
        tf.keras.metrics.Precision(name='precision'),
        tf.keras.metrics.Recall(name='recall')
    ]
)

history = model.fit(X_train_scaled, y_train, epochs=100)

predictions = model.predict(X_test_scaled)

prediction_classes = [
    1 if prob > 0.5 else 0 for prob in np.ravel(predictions)
]

print(prediction_classes)

model.save('model.h5')
