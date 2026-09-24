# JSON for Beginners

JSON stands for JavaScript Object Notation. It is a lightweight way to store and exchange data.

JSON is commonly used in:
- web APIs
- configuration files
- saving data in applications
- sending data between a server and a client

## Why JSON is useful

- easy to read and write
- easy for machines to parse
- works well with Python, JavaScript, Java, and many other languages
- uses a simple text format

## JSON syntax rules

1. Data is written in key-value pairs.
2. Keys must be strings and are wrapped in double quotes.
3. Values can be strings, numbers, booleans, arrays, objects, or null.
4. Curly braces {} represent objects.
5. Square brackets [] represent arrays.
6. Commas separate values.

## Example JSON

```json
{
  "name": "Alice",
  "age": 25,
  "isStudent": false,
  "hobbies": ["reading", "music", "traveling"],
  "address": {
    "city": "Nairobi",
    "country": "Kenya"
  }
}
```

## JSON data types

### String
```json
"hello"
```

### Number
```json
42
```

### Boolean
```json
true
```

### Null
```json
null
```

### Array
```json
[1, 2, 3, 4]
```

### Object
```json
{
  "firstName": "John",
  "lastName": "Doe"
}
```

## JSON in Python

Python has a built-in module called `json`.

```python
import json

data = {
    "name": "Alice",
    "age": 25
}

json_string = json.dumps(data)
print(json_string)
```

This converts a Python dictionary into a JSON string.

```python
import json

json_string = '{"name": "Alice", "age": 25}'
python_data = json.loads(json_string)
print(python_data)
```

This converts a JSON string into a Python dictionary.

## Common JSON methods in Python

- `json.dumps()` → convert Python object to JSON string
- `json.loads()` → convert JSON string to Python object
- `json.dump()` → write JSON data to a file
- `json.load()` → read JSON data from a file

## Simple example

```python
import json

person = {
    "name": "Mary",
    "age": 22,
    "city": "Kisumu"
}

with open("person.json", "w") as file:
    json.dump(person, file)
```

This saves the dictionary into a file called `person.json`.

## Quick summary

JSON is a standard format for storing and exchanging structured data. It is easy to read, easy to use, and works very well with Python.

## Practice idea

Try creating a JSON object like this:

```json
{
  "course": "Python",
  "lesson": "JSON",
  "students": 20
}
```

Then try using Python to load and print it.
