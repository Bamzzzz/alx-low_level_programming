#!/usr/bin/python3
def is_palindrome(number):
    return str(number) == str(number)[::-1]

largest_palindrome = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

# Save the result to the file
with open('102-result', 'w') as file:
    file.write(str(largest_palindrome))
