!/bin/bash
make re ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 5 500 200 200