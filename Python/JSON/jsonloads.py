import json

data = '{"name" : "Lomunyak Isaya","school": "Oloitoktok Boys","age": 56,"subject": "English"}'
x = json.loads(data)
print(x)
y = json.dumps(x)
print(y)
