# flask server
from flask import Flask, redirect, url_for, request
import json
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

# convert into dataframe with headers = eduroam  ucd-guest  testwifi  home1 location  DDC-ESDC  Lance2152
headers = ["eduroam",  "ucd-guest",  "testwifi",
           "home1", "location", "DDC-ESDC",  "Lance2152"]

model = tf.keras.models.load_model('model.h5')

app = Flask(__name__)

# header = ['eec172', 'testwifi', 'ucdguest', 'eduroam']
with open('json_data.json', 'a') as f:
    # if empty, write [
    if f.tell() == 0:
        f.write('[\n')
    f.close()


@app.route("/")
def home():
    return "Hello, World!"

# post request


@app.route("/post", methods=["POST"])
def post():
    # print the body of the request
    print(request.get_json())
    # write to csv
    ''' with open('json_data.json', 'a') as f:
        data = request.get_json()
        # set location of data to "inside"
        data['location'] = "outside"
        json.dump(data, f)
        f.write(',\n')
        f.close() '''
    data = request.get_json()
    df = pd.DataFrame(data, index=[0], columns=headers)
    df.fillna(0, inplace=True)
    df.drop('location', axis=1, inplace=True)
    x_scaled = scaler.transform(df)
    predictions = model.predict(np.array([x_scaled[0], ]))

    prediction_classes = [
        1 if prob > 0.5 else 0 for prob in np.ravel(predictions)
    ]

    print(prediction_classes)
    # return same json back
    return request.get_json()


if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
