#!/usr/bin/python3

import os
import sys
import json
import cgi

env_vars = [
    'REQUEST_METHOD',
    'SCRIPT_NAME',
    'QUERY_STRING',
    'SERVER_NAME',
    'CONTENT_TYPE',
]

# Prints out http headers
print("HTTP/1.1 200 OK\r")
print("Content-Type: text/html\r")
print("\r")

print("<!DOCTYPE html><html lang=\"en\"><body>")
print("<h1> POST CGI </h1>")

for var_name in env_vars:
    print("<p>ENV Variable %s = %s</p>" % (var_name, os.environ[var_name]))

# If the request method is POST, read the request body
if os.environ.get('REQUEST_METHOD', '') == 'POST':
    content_length = int(os.environ.get('CONTENT_LENGTH', 0))
    print("<p>Reading CONTENT_LENGTH: %d</p>" % content_length)
    if os.environ.get('CONTENT_TYPE', '').startswith('multipart/form-data'):
        # Reads the form
        form = cgi.FieldStorage()
        print("<p>POST multipart/form-data form: %s</p>" % form)

        # Extracts the fields "number1" and "number2"
        number1 = form.getvalue('number1', 0)
        number2 = form.getvalue('number2', 0)

        # Converts the values to integers and sums them up
        sum = int(number1) + int(number2)

        # Prints the result
        print("<p>The sum of number1 and number2 is: %d</p>" % sum)

    else:
        post_data = sys.stdin.read()
        print("<p>POST data: %s</p>" % post_data)

print("</body></html>")