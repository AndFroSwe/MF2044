function simple_init(Ts)
ttInitKernel('prioFP')
data.K = 2; % controller proportional gain
data.wcet = Ts; % control task execution time
starttime = 0.0; % control task start time
period = Ts; % control task period
ttCreatePeriodicTask('ctrl_task', starttime, period, 'ctrl_code', data);
ttSetPriority(2, 'ctrl_task');

%Disturb task added, task 5
ttCreatePeriodicTask('disturb_task', 0, Ts, 'disturb_code');
ttSetPriority(1, 'disturb_task');

%Deadline overrun handler
ttCreateHandler('handler_task', 1, 'handler_code');
ttAttachDLHandler('ctrl_task', 'handler_task');


