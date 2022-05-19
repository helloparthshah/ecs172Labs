# flask server
from flask import Flask, redirect, url_for, request
import json
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
    with open('json_data.json', 'a') as f:
        json.dump(request.get_json(), f)
        f.write(',\n')
        f.close()
    # return same json back
    return request.get_json()



if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
