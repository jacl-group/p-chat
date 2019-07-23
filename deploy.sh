#!/usr/bin/env bash

ssh jclchat.com 'cd ~/chat ; ./kill.sh'
scp src/cmake-build-debug/app/chat jclchat.com:~/chat/
scp src/cmake-build-debug/PServer/libPServer.so jclchat.com:~/chat/
ssh jclchat.com 'cd ~/chat ; ./run.sh'
