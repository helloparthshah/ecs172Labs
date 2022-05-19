import numpy as np
import pandas
from keras.models import Sequential
from keras.layers import Dense
from keras.wrappers.scikit_learn import KerasClassifier
from keras.utils import np_utils
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold
from sklearn.preprocessing import LabelEncoder
from sklearn.pipeline import Pipeline

df = pandas.read_json('inside.json')
# replace nan with -1000
df.fillna(0, inplace=True)
dataset = df.values
X = dataset[:, df.columns != 'location'].astype(float)
# multiple all values by -1
X[:, :] = X[:, :] * -1/100
Y = dataset[:, 4]

encoder = LabelEncoder()
encoder.fit(Y)
encoded_Y = encoder.transform(Y)
# convert integers to dummy variables (i.e. one hot encoded)
dummy_y = np_utils.to_categorical(encoded_Y)
print(dummy_y)

# define baseline model
print(X)


def baseline_model():
    # create model
    model = Sequential()
    model.add(Dense(10, activation='relu'))
    model.add(Dense(10, activation='relu'))
    model.add(Dense(2, activation='softmax'))
    # Compile model
    model.compile(loss='categorical_crossentropy',
                  optimizer='rmsprop', metrics=['accuracy'])
    return model


model = baseline_model()
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
