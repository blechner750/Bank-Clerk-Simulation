# Bank-Clerk-Simulation

Problem:
How effective would hiring more tellers in a bank be, given a constant flow of customers requiring various services, for various duration's of time?

In this simulation, there are a  couple different components that can be modified. There are different services that can be offered, a customize-able rate of customer arrival, simulation run-time, and teller amount.
The simulation is pre-loaded with 4 services, all with different service times. There is deposit and withdrawal which will take 1 min, account services which take 5 mins, and transfer which will take 2 mins. There is an option to add services to the list.
The user will choose how many customers with each service will arrive each minute. An array is created with this input and is randomized as to improve the dynamics of the simulation. The user then will input a time to run, and the amount of tellers given. The program will then show the current wait time during each minute, and will calculate the average wait time for the course of the simulation.

For 10 customers arriving every minute for 10 minutes:
With 1 teller, the wait time at the end is 91 minutes, and the average wait time is 50.5 minutes.
With 2 tellers, the wait time at the end is 41 minutes, and the average wait time is 23 minutes.
With 10 tellers, the wait time at the end is 1 minute, and the average wait time is 1 minute.


NOTE FOR USAGE:

To use the program, use the .exe file included in the folder: ..\Debug\ConsoleApplication4.exe(or Project.exe)

Also included are the class and sequence diagrams.
