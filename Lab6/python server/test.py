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

data = {"testwifi": -33, "eduroam": -54, "ucd-guest": -
        79, "home1": -74, "location": "inside"}

# convert into dataframe with headers = eduroam  ucd-guest  testwifi  home1 location  DDC-ESDC  Lance2152
headers = ["eduroam",  "ucd-guest",  "testwifi",
           "home1", "location", "DDC-ESDC",  "Lance2152"]

# modify data to have the headers
df = pd.DataFrame(data, index=[0], columns=headers)
df.fillna(0, inplace=True)
df.drop('location', axis=1, inplace=True)
x_scaled = scaler.transform(df)

model = tf.keras.models.load_model('model.h5')
predictions = model.predict(np.array([x_scaled[0], ]))

prediction_classes = [
    1 if prob > 0.5 else 0 for prob in np.ravel(predictions)
]

print(prediction_classes)
