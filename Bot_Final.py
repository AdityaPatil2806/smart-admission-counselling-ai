import json
import os
import textsim2


chatlist = [] 
prevQuestion = "default"

class UltraChatBot:
    def __init__(self, json_data):
        self.json_data = json_data
        self.dict_messages = json_data['data']

    def process_incoming_message(self, incoming_message):
        data = text_similarity(incoming_message)
        print(data)
        return data

try:
    os.remove("database.sqlite3")
except FileNotFoundError:
    print("Database file not found. Continuing...")

# Load your custom data from a JSON file
with open('Questions.json', 'r', encoding="utf8") as file:
    college_data = json.load(file)

# Greet the user
print("Bot: Hello, may I help you?")

def text_similarity(sentence1):
    global prevQuestion
    global college_data
    output = ""
    dist = 0
    myList = []
    
    print("Previous Question: " + prevQuestion)

    # Check for training command
    if "yes:" in sentence1.lower():
        sentence1 = sentence1.replace("yes:", "").replace("Yes:", "")
        new_data = [prevQuestion, sentence1]
        college_data.append(new_data)

        # Write updated data back to MH_Que.json
        with open('Questions.json', 'w', encoding="utf8") as file:
            json.dump(college_data, file, ensure_ascii=False, indent=4)
        return "Data added to the database."

    # Check for single word matches
    for input_text, response_text in college_data:
        if textsim2.count_matching_words(input_text, sentence1) > 0:  # Match if at least one word matches
            output = response_text
            break

    if output == "":
        output = "I'm sorry, I couldn't understand your question. If you want to train me, please type 'yes:answer'."
        prevQuestion = sentence1

    return output
