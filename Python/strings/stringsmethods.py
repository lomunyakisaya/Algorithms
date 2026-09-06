# ============================================================
# PYTHON STRING METHODS - PRACTICE 
# ============================================================

# A string
text = "  Hello Python World  "

print("=" * 60)
print("PYTHON STRING METHODS")
print("=" * 60)


# ------------------------------------------------------------
# 1. len()
# Returns the number of characters in a string
# ------------------------------------------------------------

print("\n1. len()")
print(len(text))


# ------------------------------------------------------------
# 2. upper()
# Converts all letters to uppercase
# ------------------------------------------------------------

print("\n2. upper()")
print(text.upper())


# ------------------------------------------------------------
# 3. lower()
# Converts all letters to lowercase
# ------------------------------------------------------------

print("\n3. lower()")
print(text.lower())


# ------------------------------------------------------------
# 4. capitalize()
# Makes the first character uppercase
# ------------------------------------------------------------

print("\n4. capitalize()")
print(text.capitalize())


# ------------------------------------------------------------
# 5. title()
# Makes the first letter of every word uppercase
# ------------------------------------------------------------

print("\n5. title()")
print(text.title())


# ------------------------------------------------------------
# 6. swapcase()
# Changes uppercase to lowercase and lowercase to uppercase
# ------------------------------------------------------------

print("\n6. swapcase()")
print(text.swapcase())


# ------------------------------------------------------------
# 7. strip()
# Removes spaces from both ends
# ------------------------------------------------------------

print("\n7. strip()")
print(text.strip())


# ------------------------------------------------------------
# 8. lstrip()
# Removes spaces from the LEFT side
# ------------------------------------------------------------

print("\n8. lstrip()")
print(text.lstrip())


# ------------------------------------------------------------
# 9. rstrip()
# Removes spaces from the RIGHT side
# ------------------------------------------------------------

print("\n9. rstrip()")
print(text.rstrip())


# ------------------------------------------------------------
# 10. replace()
# Replaces one piece of text with another
# ------------------------------------------------------------

print("\n10. replace()")
print(text.replace("Python", "Rust"))


# ------------------------------------------------------------
# 11. split()
# Breaks a string into a list
# ------------------------------------------------------------

print("\n11. split()")
print(text.split())


# ------------------------------------------------------------
# 12. split() with a separator
# ------------------------------------------------------------

print("\n12. split(',')")
fruits = "apple,banana,mango"
print(fruits.split(","))


# ------------------------------------------------------------
# 13. join()
# Joins items together into one string
# ------------------------------------------------------------

print("\n13. join()")
words = ["Python", "is", "powerful"]
print(" ".join(words))


# ------------------------------------------------------------
# 14. find()
# Returns the index of the first occurrence
# Returns -1 if not found
# ------------------------------------------------------------

print("\n14. find()")
print(text.find("Python"))


# ------------------------------------------------------------
# 15. rfind()
# Finds the LAST occurrence
# ------------------------------------------------------------

print("\n15. rfind()")
example = "hello hello hello"
print(example.rfind("hello"))


# ------------------------------------------------------------
# 16. index()
# Similar to find(), but raises an error if not found
# ------------------------------------------------------------

print("\n16. index()")
print(text.index("Python"))


# ------------------------------------------------------------
# 17. count()
# Counts how many times something appears
# ------------------------------------------------------------

print("\n17. count()")
print(example.count("hello"))


# ------------------------------------------------------------
# 18. startswith()
# Checks whether a string starts with something
# ------------------------------------------------------------

print("\n18. startswith()")
print(text.startswith("  Hello"))


# ------------------------------------------------------------
# 19. endswith()
# Checks whether a string ends with something
# ------------------------------------------------------------

print("\n19. endswith()")
print(text.endswith("  "))


# ------------------------------------------------------------
# 20. isalpha()
# True if ALL characters are alphabetic
# ------------------------------------------------------------

print("\n20. isalpha()")
print("Python".isalpha())
print("Python123".isalpha())


# ------------------------------------------------------------
# 21. isdigit()
# True if ALL characters are digits
# ------------------------------------------------------------

print("\n21. isdigit()")
print("12345".isdigit())
print("123abc".isdigit())


# ------------------------------------------------------------
# 22. isalnum()
# True if ALL characters are letters or numbers
# ------------------------------------------------------------

print("\n22. isalnum()")
print("Python123".isalnum())
print("Python 123".isalnum())


# ------------------------------------------------------------
# 23. isspace()
# True if the string contains only whitespace
# ------------------------------------------------------------

print("\n23. isspace()")
print("   ".isspace())
print("Hello".isspace())


# ------------------------------------------------------------
# 24. islower()
# Checks whether all letters are lowercase
# ------------------------------------------------------------

print("\n24. islower()")
print("hello".islower())
print("Hello".islower())


# ------------------------------------------------------------
# 25. isupper()
# Checks whether all letters are uppercase
# ------------------------------------------------------------

print("\n25. isupper()")
print("HELLO".isupper())
print("Hello".isupper())


# ------------------------------------------------------------
# 26. istitle()
# Checks whether each word starts with uppercase
# ------------------------------------------------------------

print("\n26. istitle()")
print("Hello World".istitle())
print("hello world".istitle())


# ------------------------------------------------------------
# 27. isidentifier()
# Checks whether the string is a valid Python identifier
# ------------------------------------------------------------

print("\n27. isidentifier()")
print("my_variable".isidentifier())
print("123variable".isidentifier())


# ------------------------------------------------------------
# 28. isprintable()
# Checks whether all characters can be printed
# ------------------------------------------------------------

print("\n28. isprintable()")
print("Hello".isprintable())
print("Hello\n".isprintable())


# ------------------------------------------------------------
# 29. center()
# Centers the string
# ------------------------------------------------------------

print("\n29. center()")
print("Python".center(20, "-"))


# ------------------------------------------------------------
# 30. ljust()
# Aligns text to the LEFT
# ------------------------------------------------------------

print("\n30. ljust()")
print("Python".ljust(20, "-"))


# ------------------------------------------------------------
# 31. rjust()
# Aligns text to the RIGHT
# ------------------------------------------------------------

print("\n31. rjust()")
print("Python".rjust(20, "-"))


# ------------------------------------------------------------
# 32. zfill()
# Adds zeros to the LEFT
# ------------------------------------------------------------

print("\n32. zfill()")
print("42".zfill(5))


# ------------------------------------------------------------
# 33. partition()
# Splits into THREE parts:
# before separator, separator, after separator
# ------------------------------------------------------------

print("\n33. partition()")
print("name=Isaiah".partition("="))


# ------------------------------------------------------------
# 34. rpartition()
# Same as partition(), but searches from the RIGHT
# ------------------------------------------------------------

print("\n34. rpartition()")
print("one-two-three".rpartition("-"))


# ------------------------------------------------------------
# 35. removeprefix()
# Removes something from the beginning
# ------------------------------------------------------------

print("\n35. removeprefix()")
print("Mr. Isaiah".removeprefix("Mr. "))


# ------------------------------------------------------------
# 36. removesuffix()
# Removes something from the end
# ------------------------------------------------------------

print("\n36. removesuffix()")
print("hello.py".removesuffix(".py"))


# ------------------------------------------------------------
# 37. casefold()
# Aggressive lowercase conversion
# Useful for case-insensitive comparisons
# ------------------------------------------------------------

print("\n37. casefold()")
print("HELLO".casefold())


# ------------------------------------------------------------
# 38. encode()
# Converts a string into bytes
# ------------------------------------------------------------

print("\n38. encode()")
print("Hello".encode())


# ------------------------------------------------------------
# 39. format()
# Inserts values into a string
# ------------------------------------------------------------

print("\n39. format()")
name = "Isaiah"
age = 20
print("My name is {} and I am {} years old".format(name, age))


# ------------------------------------------------------------
# 40. format_map()
# Uses a dictionary to insert values
# ------------------------------------------------------------

print("\n40. format_map()")
person = {
    "name": "Isaiah",
    "age": 20
}

print("My name is {name} and I am {age}".format_map(person))


# ============================================================
# STRING INDEXING
# ============================================================

print("\n" + "=" * 60)
print("STRING INDEXING")
print("=" * 60)

a = "Iamaboy"

# Index:
#
#  I   a   m   a   b   o   y
#  0   1   2   3   4   5   6
#
# Negative:
#
# -7 -6 -5 -4 -3 -2 -1

print("\nOriginal:", a)

print("a[0]   =", a[0])
print("a[1]   =", a[1])
print("a[-1]  =", a[-1])
print("a[-2]  =", a[-2])


# ============================================================
# STRING SLICING
# ============================================================

print("\n" + "=" * 60)
print("STRING SLICING")
print("=" * 60)

# [start:stop]
# start is INCLUDED
# stop is EXCLUDED

print("a[:4]  =", a[:4])      # Iama
print("a[5:]  =", a[5:])      # oy
print("a[1:4] =", a[1:4])     # ama
print("a[:]   =", a[:])       # entire string


# ============================================================
# SLICING WITH STEP
# ============================================================

print("\n" + "=" * 60)
print("SLICING WITH STEP")
print("=" * 60)

# [start:stop:step]

print("a[::2]  =", a[::2])
print("a[::3]  =", a[::3])

# Reverse a string
print("a[::-1] =", a[::-1])


# ============================================================
# STRING CONCATENATION
# ============================================================

print("\n" + "=" * 60)
print("STRING CONCATENATION")
print("=" * 60)

first = "Hello"
second = "World"

print(first + " " + second)


# ============================================================
# STRING REPETITION
# ============================================================

print("\nString repetition:")
print("Python " * 3)


# ============================================================
# MEMBERSHIP
# ============================================================

print("\nMembership:")

print("Python" in "I love Python")
print("Java" not in "I love Python")


# ============================================================
# F-STRINGS
# Modern and recommended way to insert variables
# ============================================================

print("\n" + "=" * 60)
print("F-STRINGS")
print("=" * 60)

name = "Isaiah"
age = 20

print(f"My name is {name} and I am {age} years old.")


# ============================================================
# END
# ============================================================

print("\n" + "=" * 60)
print("END OF STRING PRACTICE")
print("=" * 60)