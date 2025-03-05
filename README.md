# Philosophers
This project is where we have to simulate the famous dining philosophers problem. [[The Dining Philosophers Problem]](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

**(I just did the mandatory part.)**

# Objectives
- Learn about threads
- Learn about mutex locks
- Manage Shared Resources
- Avoid deadlocks
- Avoid race conditions
 
# Approach
To begin with i have 2 types of a philosopher thread and a monitor thread.

- Monitor thread: The monitor thread will check for 2 things only, it will check if there is a dead philosopher id so it will set the dead_philo flag to 1 ```prog->dead_philo = 1``` and if the number of meals was also provided with the input it will check if all of the philosophers have eaten their meals if so it will also set the dead_philo flag to 1 ```prog->dead_philo = 1``` and it will end the simulation.

- Philosopher thread: The first thing we check in the philosopher thread is if there is only 1 philosopher which is a special case since there will be only 1 fork on the table and will to starvation. If there are more than 1 philosopher we will make every odd philosopher to wait for 1ms to avoid deadlocks. The philosopher have 5 states (Trying to pick up a fork, eating, sleeping, dropping the fork, thinking). The way the philosopher picks up the fork is first by locking that fork mutex to avoid race conditions and then will check if it is availale if so he will pick it up and set the status of that fork to 1 ```p->prog->forks[p->id] = 1``` else he will wait for a short time then try to pick that fork again. The way i calculate the position of the left fork is ```p->id```, the right fork is a bit different and is caluclated as the following: ```position = (p->id + 1) % p->prog->n_philo``` where it will ensure that the philosopher will pick up the correct fork. After picking up the forks the philosopher will lock his meal mutex and set the last_meal to the current time: ```p->last_meal = gtms()``` then he will unlock his meal mutex and then sleep for time_to_eat. After he finished eating he sleep 

# Running Instructions
```make ```

```./philo number_of_philosophers time_to_die time_to_eat time_to_sleep```

# Examples

```./philo 5 600 200 200``` **(This will have a philosopher die due to starvation)**
```
0 0 has taken a fork
0 0 has taken a fork
0 0 is eating
0 4 has taken a fork
0 2 has taken a fork
0 2 has taken a fork
0 2 is eating
200 0 is sleeping
200 4 has taken a fork
200 4 is eating
200 1 has taken a fork
200 1 has taken a fork
200 1 is eating
200 3 has taken a fork
200 2 is sleeping
400 0 is thinking
400 2 is thinking
400 3 has taken a fork
400 3 is eating
400 4 is sleeping
400 1 is sleeping
400 2 has taken a fork
400 0 has taken a fork
400 0 has taken a fork
400 0 is eating
600 2 died
```

```./philo 5 600 100 100``` **(This one will run infinitely)**
```
1 0 has taken a fork
1 0 has taken a fork
1 0 is eating
1 2 has taken a fork
1 2 has taken a fork
1 2 is eating
1 4 has taken a fork
101 2 is sleeping
101 3 has taken a fork
101 0 is sleeping
101 4 has taken a fork
101 4 is eating
101 1 has taken a fork
101 1 has taken a fork
101 1 is eating
201 2 is thinking
201 0 is thinking
201 1 is sleeping
201 4 is sleeping
201 2 has taken a fork
201 0 has taken a fork
201 0 has taken a fork
201 0 is eating
201 3 has taken a fork
201 3 is eating
301 3 is sleeping
301 4 is thinking
301 4 has taken a fork
301 4 has taken a fork
301 4 is eating
301 0 is sleeping
301 2 has taken a fork
301 2 is eating
301 1 is thinking
301 1 has taken a fork
401 2 is sleeping
401 1 has taken a fork
401 1 is eating
```

```./philo 3 310 100 100 2``` **(All philosophers will eat)**
```
0 0 has taken a fork
1 0 has taken a fork
1 0 is eating
1 2 has taken a fork
101 0 is sleeping
101 1 has taken a fork
101 2 has taken a fork
101 2 is eating
201 2 is sleeping
201 1 has taken a fork
201 1 is eating
201 0 is thinking
201 0 has taken a fork
301 1 is sleeping
301 2 is thinking
301 2 has taken a fork
301 0 has taken a fork
301 0 is eating
401 1 is thinking
401 0 is sleeping
401 1 has taken a fork
401 2 has taken a fork
401 2 is eating
501 2 is sleeping
501 0 is thinking
501 0 has taken a fork
501 1 has taken a fork
501 1 is eating
```
