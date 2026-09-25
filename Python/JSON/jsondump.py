import json
data = {
    "name": "Lomunyak Isaya",
    "school": "Oloitoktok Boys",
    "age": 56,
    "subject": "English"
}
message = json.dumps(data)
print(message)