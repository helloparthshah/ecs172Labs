# flask server
from flask import Flask, redirect, url_for, request

app = Flask(__name__)


@app.route("/")
def home():
    return "Hello, World!"

# post request
app.route("/post", methods=["POST"])
def post():
    # print the body of the request
    print(request.get_json())
    # return same json back
    return request.get_json()



if __name__ == "__main__":
    app.run(debug=True)
