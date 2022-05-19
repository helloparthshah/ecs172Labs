# load model from disk

from numpy import NaN
import pandas
from tensorflow import keras
model = keras.models.load_model('model.h5')

df = pandas.read_json('inside.json')
dataset = df.values
X = dataset[:, df.columns != 'location'].astype(float)
Y = dataset[:, 4]

print(model.predict(X))
