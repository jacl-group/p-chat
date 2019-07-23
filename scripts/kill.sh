#!/usr/bin/env bash

FILE=~/chat/chat.pid
if [[ -f "$FILE" ]]; then
    PID=`cat ${FILE}`
    #echo "pid=${PID}"
else
    echo "No ${FILE}"
    if [[ -z $1 ]]; then
	echo "No arg"
	exit 1
    fi
fi

echo "kill -1 ${PID} $1 $2 $3 $4"
kill -1 ${PID} $1 $2 $3 $4
rm -f ${FILE}
