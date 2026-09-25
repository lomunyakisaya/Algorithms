# Python File Handling Notes

## 1. What is file handling?
File handling means working with files on the computer using Python.
It allows us to:
- read data from files
- write data into files
- update existing files
- delete or manage files

Python uses built-in functions to work with files.

---

## 2. Opening a file
To work with a file, we first open it using the `open()` function.

```python
file = open("example.txt", "r")
```

### Syntax
```python
open(file_name, mode)
```

### Common file modes
- `"r"` - read mode
- `"w"` - write mode
- `"a"` - append mode
- `"rb"` - read binary
- `"wb"` - write binary
- `"x"` - create a new file for writing

Example:
```python
f = open("data.txt", "r")
```

---

## 3. Reading from a file
There are several ways to read files.

### Read the whole file
```python
f = open("data.txt", "r")
content = f.read()
print(content)
f.close()
```

### Read one line
```python
f = open("data.txt", "r")
line = f.readline()
print(line)
f.close()
```

### Read all lines
```python
f = open("data.txt", "r")
lines = f.readlines()
print(lines)
f.close()
```

### Best practice
Always close the file after reading or writing:
```python
f.close()
```

---

## 4. Writing to a file
To write to a file, use the `"w"` mode.

```python
f = open("data.txt", "w")
f.write("Hello, Python!\n")
f.write("This is file handling.")
f.close()
```

### Important
Using `"w"` overwrites the file completely.
If the file does not exist, Python creates it.

---

## 5. Appending to a file
Use `"a"` to add content to the end of the file without deleting previous content.

```python
f = open("data.txt", "a")
f.write("\nThis line is appended.")
f.close()
```

---

## 6. Creating a new file
Use `"x"` to create a file only if it does not already exist.

```python
f = open("newfile.txt", "x")
f.write("This is a new file.")
f.close()
```

---

## 7. The with statement
A safer and cleaner way to work with files is using `with`.

```python
with open("data.txt", "r") as f:
    data = f.read()
    print(data)
```

### Why use `with`?
- automatically closes the file
- reduces errors
- cleaner code

---

## 8. File positions
Python keeps track of where it is reading or writing inside a file.

### Tell current position
```python
with open("data.txt", "r") as f:
    print(f.tell())
```

### Move to a specific position
```python
with open("data.txt", "r") as f:
    f.seek(5)
    print(f.read())
```

---

## 9. Reading and writing text files
Text files store normal characters and are easy to read.

```python
with open("notes.txt", "w") as f:
    f.write("Python is fun")
```

To read:
```python
with open("notes.txt", "r") as f:
    print(f.read())
```

---

## 10. Binary files
Binary files store data in binary form, such as images, videos, or executable files.

```python
with open("image.bin", "wb") as f:
    f.write(b"\x00\x01\x02\x03")
```

To read binary:
```python
with open("image.bin", "rb") as f:
    data = f.read()
    print(data)
```

---

## 11. File methods
Some common file methods are:

- `read()` - reads all content
- `readline()` - reads a single line
- `readlines()` - reads all lines into a list
- `write()` - writes text to a file
- `writelines()` - writes multiple lines
- `close()` - closes the file
- `seek()` - moves the file pointer
- `tell()` - returns current position

Example:
```python
with open("example.txt", "w") as f:
    f.writelines(["one\n", "two\n", "three\n"])
```

---

## 12. Deleting files
To delete a file, use the `os` module.

```python
import os

if os.path.exists("example.txt"):
    os.remove("example.txt")
    print("File deleted")
else:
    print("File not found")
```

---

## 13. Renaming files
```python
import os

os.rename("old_name.txt", "new_name.txt")
```

---

## 14. Checking if a file exists
```python
import os

print(os.path.exists("data.txt"))
```

---

## 15. Example program
```python
with open("student.txt", "w") as f:
    f.write("Alice\n")
    f.write("Bob\n")
    f.write("Charlie\n")

with open("student.txt", "r") as f:
    for line in f:
        print(line.strip())
```

Output:
```python
Alice
Bob
Charlie
```

---

## 16. Summary
Python file handling is used to:
- open files
- read data
- write data
- append data
- create files
- delete and rename files

The most common methods are `open()`, `read()`, `write()`, `close()`, and `with`.

---

## 17. Quick revision questions
1. What does `"r"` mode mean?
2. What is the difference between `"w"` and `"a"`?
3. Why is `with open()` preferred?
4. How do you delete a file in Python?
5. What does `readlines()` return?

---

## 18. Important note
When working with files, always be careful with write modes because `"w"` will overwrite existing content.

Use `"a"` when you want to keep existing data and add new text.
