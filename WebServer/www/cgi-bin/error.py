#!/usr/bin/python

import os

# Prints out http headers
print("HTTP/1.1 200 OK\r")
print("Content-Type: text/html\r")
print("\r")

print("<!DOCTYPE html><html lang=\"en\"><body>")

pint("<p>There are no errors in your CGI script :) </p>")

print("</body></html>")