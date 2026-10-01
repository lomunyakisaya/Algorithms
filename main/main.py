import requests

response = requestd.get("https://api.github.com")
data = response.json()
print(data)
