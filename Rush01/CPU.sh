top -l 1 | grep Processes: |  cut -d' ' -f2
top -l 1 | grep Processes: |  cut -d' ' -f4
top -l 1 | grep Processes: |  cut -d' ' -f6
top -l 1 | grep Processes: |  cut -d' ' -f8
top -l 1 | grep 'CPU usage:' |  cut -d' ' -f3
top -l 1 | grep 'CPU usage:' |  cut -d' ' -f5
top -l 1 | grep 'CPU usage:' |  cut -d' ' -f7
#Processes: 288 total, 2 running, 286 sleeping, 1229 threads
#CPU usage: 27.58% user, 27.58% sys, 44.82% idle