#!/usr/bin/python

import os

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
print("<h1> HOME </h1>")
print("<p> Hello from your CGI script :) </p>")

for var_name in env_vars:
    print("<p>ENV Variable %s = %s</p>" % (var_name, os.environ[var_name]))

print("</body></html>")