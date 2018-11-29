from server import create_app,socketio

app = create_app()

if __name__ == '__main__':
    socketio.run(app,threaded=True,port=8000,use_reloader=False,debug=True)