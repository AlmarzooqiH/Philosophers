!/bin/bash
make re ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 10 800 200 200