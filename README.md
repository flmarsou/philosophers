# 🦊 What is Philosophers?

**Philosophers** is an introduction to threads and mutexes in C. The objective is to simulate the *Dining Philosophers Problem*, which is a classic synchronization problem.

- Each philosopher (thread) sit at a table.
- Each philosopher has a fork (mutex), and they need two forks to eat.
- They take turns thinking, eating, and sleeping, but they cannot eat unless they have both forks (their own, and their neighbor's).

The problem demonstrates how to manage shared resources (forks) and avoid deadlocks and dataraces.

---

# ⚒️ Compilation

1. Run `make` to compile the program.
2. Run `make re` to recompile everything.

---

# 🖥️ Execution

**1. Run the program with:**
```bash
./philo <nbr_of_philo> <time_to_die> <time_to_eat> <time_to_sleep>
```
- `nbr_of_philo`: Number of philosophers (threads) sitting at the table.
- `time_to_die`: Time in milliseconds before a philosopher dies if they haven't eaten.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds it takes for a philosopher to sleep.


**2. Alternatively, you can run the program with an optional number of cycles:**
```bash
./philo <nbr_of_philo> <time_to_die> <time_to_eat> <time_to_sleep> <nbr_of_cycles>
```

**Rules:** \
`nbr_of_philo` must be greater than 0 and no more than 200. \
`time_to_die`, `time_to_eat`, and `time_to_sleep` cannot be lower than 60 milliseconds.

---

# 🧼 Cleaning

1. Run `make clean` to remove every object files.
2. Run `make fclean` to remove every object files, including the executable.
