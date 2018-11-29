import os
import json

from flask import Flask,request,g,jsonify,render_template
from flask_socketio import SocketIO,emit

socketio = SocketIO()

def create_app(test_config=None):
    # create and configure the app
    app = Flask(__name__, instance_relative_config=True)
    app.config.from_mapping(
        SECRET_KEY='dev',
    )

    # a simple page that says hello
    @app.route('/hello')
    def hello():
        return render_template('index.html')

    @socketio.on('update') 
    def handle_data(data): #handle received data
        print('recevied')
        # data = json.loads(data)
        print(data)
        push_data(data)
        # return 'received'

    @socketio.on('connect')
    def push_data(data=None): #push data to frontpage

        if data != None:
            socketio.emit('server_response',data)

    socketio.init_app(app)
    return app
