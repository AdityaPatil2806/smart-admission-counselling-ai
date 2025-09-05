from flask import Flask, request, jsonify, render_template
from Bot_Final import UltraChatBot  # Ensure this matches your actual bot.py filename
import json

app = Flask(__name__)

@app.route('/', methods=['POST'])
def home():
    if request.method == 'POST':
        print(request.json)
        bot = UltraChatBot(request.json)
        return jsonify(bot.process_incoming_message(request.json["data"]))

@app.route('/bot')
def index():
    return render_template('index.html')

@app.route('/mybot', methods=['POST'])
def mybot():
    if request.method == 'POST':
        print(request.json)
        bot = UltraChatBot(request.json)  # Create an instance of the bot
        return jsonify(bot.process_incoming_message(request.json["data"]))

if __name__ == '__main__':
    app.run(debug=True)
