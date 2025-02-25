!/bin/bash
make re ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 150 1200 300 250 5