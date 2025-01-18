!/bin/bash
make ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 5 100 50 20