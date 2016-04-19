function simple_init( Ts )
%SIMPLE_INIT Summary of this function goes here
%   Detailed explanation goes here

ttInitKernel('prioFP');

data.K = 2;
data.wcet = Ts;

starttime = 0.0;
period = Ts;

ttCreatePeriodicTask('ctrl_task', starttime, period, 'ctrl_code', data);
ttSetPriority(2, 'ctrl_task');


