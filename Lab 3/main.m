close all; clear all; clc;
format compact;

Ts = 0.5;

runSimAndScale('lab3');

%Answers
%4.1 One can see that there is actuation every Ts seconds. Also, each Ts
%second the task is called.
%4.2 Looking at the schedule
%4.3 The actual system. In the simulation, there is computation delay.
%4.X Yes, the performance is increased.

%5.1 Starttime = 0; Period = Ts;
%5.2 The priority of the disturbance task is 1. It runs before the control
%task.
%5.3 exectime = 0.1;
%5.4 It is marginally worse, it misses the deadline sometimes
%5.5 2 plots Low is idle, middle is preemted, high is active
%5.6 Ctrl does miss deadline sometimes. Can see that is does not go idle.
%5.X Same as without disturbance. Disturb misses deadline.

