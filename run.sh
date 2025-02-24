!/bin/bash
make re ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 5 1000 200 200