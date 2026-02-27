*This project has been created as part of the 42 curriculum by ehuet.*

# Philosophers

## Description

Philosophers is a concurrency project from the 42 curriculum based on the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra in 1965.

The simulation involves N philosophers sitting at a round table. Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**. To eat, a philosopher must pick up two forks — one on their left and one on their right. Since forks are shared between neighbors, philosophers must coordinate access to avoid deadlocks and starvation.

The goal of the project is to implement a correct, race-condition-free solution using **POSIX threads** (`pthread`) and **mutexes**, without any deadlock, and ensuring that no philosopher starves unless the given timing parameters make it unavoidable.

Key constraints:
- Each philosopher is a thread
- Each fork is protected by a mutex
- A monitoring thread watches for deaths and meal completion
- No global variables allowed
- No `exit()` calls

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./philo <nb_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]
```

| Argument | Description |
|---|---|
| `nb_philosophers` | Number of philosophers (and forks), between 1 and 199 |
| `time_to_die` | Time in ms before a philosopher dies if they haven't eaten |
| `time_to_eat` | Time in ms a philosopher spends eating |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `nb_meals` | (Optional) Simulation stops when all philosophers have eaten this many times |

### Examples

```bash
# No one should die
./philo 5 800 200 200

# One philosopher dies after 800ms
./philo 1 800 200 200

# Stops after each philosopher eats 7 times
./philo 5 800 200 200 7

# Someone will die (tight timing)
./philo 4 200 200 200
```

### Output format

```
timestamp_in_ms philosopher_id action
```

Actions: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`

## Technical Choices

- **Deadlock prevention**: even-numbered philosophers pick up their right fork first, odd-numbered pick up their left fork first, creating an asymmetry that breaks the circular wait condition
- **Race condition prevention**: shared variables (`end_simulation`, `last_meal`, `full`, `meals`) are declared `_Atomic` to guarantee indivisible reads and writes across threads
- **Death detection**: a dedicated monitor thread checks every 100µs whether any philosopher has exceeded `time_to_die` since their last meal
- **Responsive sleep**: `ft_usleep` polls `end_simulation` every 100µs instead of sleeping for the full duration, allowing threads to exit quickly after a death is detected

## Resources

### Documentation & References

- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [The dining Philosophers in C: threads, race conditions and deadlocks #codewithme ](https://www.youtube.com/watch?v=zOpzGHwJ3MU&t=2141s)

### AI Usage

Claude (Anthropic) was used throughout this project as a **learning and debugging assistant**:

- **Conceptual explanations**: understanding mutex mechanics, deadlock conditions, race conditions, and the difference between atomic operations and mutexes
- **Code review**: identifying bugs such as uninitialized variables, missing `i++` in loops, incorrect fork assignment logic, and prototype mismatches
- **Debugging**: diagnosing why the simulation was blocking (deadlock from symmetric fork ordering), why timestamps were incorrect (missing `start_time` initialization), and why the program kept running after a death (blocking `pthread_mutex_lock` and non-interruptible `usleep`)
- **Norm compliance**: reformatting functions to stay under 25 lines and 5 functions per file following the 42 norm

All code was written and understood by the student — AI was used to accelerate understanding, not to replace it.
