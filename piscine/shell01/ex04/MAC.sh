#!/bin/sh
ifconfig |grep ether | grep ether | cut -d ' ' -f 2
