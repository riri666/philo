# Philosophers : *I never thought philosophy would be so deadly*

> In this project, you will learn the  the basics of threading a process.You will see how to create threads and you will discover mutexes.

This project is about implementing **The Dining Philosophers Problem**, which is an example problem often used in **concurrent algorithm** design to illustrate synchronization issues and techniques for resolving them.

Here are the rules that should be respected :
- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively **eat**, **think**, or **sleep**.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are **as many forks as philosophers**.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying !

The use of **mutexes** was crucial to avoid **data races**, that is possible by protecting variables (locking and unlocking) since threads are a part of the same processus was the only way to prevent mistaken results.

*Discovering threads and implementing The Dining Philosophers Problem was a very interesting assignment !* 
