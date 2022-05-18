# flask server
from flask import Flask, redirect, url_for, request
import csv
import json
app = Flask(__name__)

header = ['eec172', 'testwifi', 'ucdguest', 'eduroam']
f = open('./data.csv', 'w')
writer = csv.DictWriter(f, fieldnames=header)
writer.writeheader()

@app.route("/")
def home():
    return "Hello, World!"

# post request
@app.route("/post", methods=["POST"])
def post():
    # print the body of the request
    print(request.get_json())
    # write to csv
    writer.writerow(request.get_json())
    # return same json back
    return request.get_json()



if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
