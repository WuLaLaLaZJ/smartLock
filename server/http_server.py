#先运行pip install flask
#首先我们使用 Python 搭建一个简单的 HTTP 服务，用来接收 POST / 请求，该服务打印请求内容后返回 200 OK

from flask import Flask, json, request

api = Flask(__name__)

@api.route('/', methods=['POST'])
def print_messages():
  reply= {"result": "ok", "message": "success"}
  print("got post request: ", request.get_data())
  return json.dumps(reply), 200

if __name__ == '__main__':
  api.run()