#!/usr/bin/env bash

rm $1
####
exec 3>&1 4>&2
trap 'exec 2>&4 1>&3' 0 1 2 3
exec 1>$1 2>&1
####
# Everything below will go to the file given as argument

# Get IP addresses
echo "Last update: $(date)"
echo
echo "--- Hostname ---"
hostname
echo
echo "--- IP ADDRESSES ---"
ip -f inet a | awk '/inet / { print $2 }'
echo
echo "--- FREE RAM ---"
free -m
echo
echo "--- FREE DISK ---"
df -h /
echo
echo "--- Load Avg ---"
uptime
echo
echo "--- Kernel Info ---"
uname -a
echo
