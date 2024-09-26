from flask import Flask, request

app = Flask(__name__)

@app.route('/post-data', methods=['POST'])
def post_data():
    data = request.data.decode('utf-8')  # Get the raw POST data
    with open('received_data.txt', 'a') as f:
        f.write(data + '\n')  # Append the data to the text file
    return 'Data received!', 200

if __name__ == '__main__':
    app.run(host='192.168.137.1', port=8000)
