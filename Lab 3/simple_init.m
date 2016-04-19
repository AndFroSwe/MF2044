function simple_init(Ts)
ttInitKernel('prioFP')
data.K = 2; % controller proportional gain
data.wcet = Ts; % control task execution time
starttime = 0.0; % control task start time
period = Ts; % control task period
ttCreatePeriodicTask('ctrl_task', starttime, period, 'ctrl_code', data)


