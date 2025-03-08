!/bin/bash
make re ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 185 1000 500 500 1 > out.txt