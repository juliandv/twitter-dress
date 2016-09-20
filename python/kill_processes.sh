#/bin/sh
ps -ef | grep 'streaming.p[y]' | awk '{print $2}' | xargs kill -9
