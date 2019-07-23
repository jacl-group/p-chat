#!/usr/bin/env bash

FILE=~/chat/chat.pid

export LD_LIBRARY_PATH=${HOME}/local/lib:${HOME}/chat
./chat --daemon --pidfile=${FILE} $1 $2 $3 $4 
#./chat  $1 $2 $3 $4 

