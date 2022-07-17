# philosophers
This project teaches you how to work with threads in C.
##Mandatory part:
The program's arguments:
- **number of philosophers**: The number of philosophers and also the number of forks.
- **time to die**(ms): If this time passed and the philosopher stayed without eating, they die.
- **time to eat**(ms): The time it takes for each philosopher to eat. (**in order to eat he will need to hold _two forks_**)
- **time to sleep**(ms): The time it takes for each philosopher to sleep.
- **number of times each philosopher must eat** ***optional argument***: if all have eaten at least this number of time the simulation stops.
Each philosopher is a _thread_.
States must be printed this way:
- **timestamp_in_ms X has taken a fork**
- **timestamp_in_ms X is eating**
- **timestamp_in_ms X is sleeping**
- **timestamp_in_ms X is thinking**
- **timestamp_in_ms X died**
*X is the philosopher number*
State messages must not be mixed up with another message.
The message announcing the death of a philosopher should be displayed no more than 10 ms.
**The program must not have any _data races_.**
