#!/usr/bin/env bash

ps -ef | grep -v grep | grep chat
FILE='chat.pid'
if [[ -e ${FILE} ]]; then
	echo -n "${FILE}: "
	cat ${FILE}
fi

