!/bin/bash
make ; clear ; valgrind --tool=helgrind -s --log-file="out.log" ./philo 3 50 100 200