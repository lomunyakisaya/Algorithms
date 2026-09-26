
import requests

response = requests.get("http://google.com")
print(response.status_code)
#print(response.text)
print(response.url)

import requests

response = requests.get("https://jsonplaceholder.typicode.com/users")

print(response.status_code)
print(response.text)
import requests

response = requests.get("https://jsonplaceholder.typicode.com/users")
data = response.json()
for user in data:
    print(len(user["name"]))
import requests
response = requests.get("https://narropilafricansafaris-production.up.railway.app/")
print(response.text)
