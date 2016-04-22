function simple_init(Ts)
prio = {'prioDM', 'prioFP', 'prioEDF'};
choise = 1;
disp(prio{choise});

ttInitKernel(prio{choise});

% Task attributes
starttime = 0.0; % control task start time
period = 0.005; % control task period
deadline = period;

% Create task data (local memory)
data.K = 1;
data.Ti = 0.12;
data.Td = 0.049;
data.beta = 0.5;
data.N = 10;
data.h = period;

%Help parameters PID
data.u = 0;
data.Iold = 0;
data.Dold = 0;
data.yold = 0;

%Data channels
data.rChan = 1;
data.yChan = 2;
data.uChan = 1;

data.t = 0;


ttCreatePeriodicTask('pid_task', starttime, period, 'pid_code', data);
ttSetPriority(2, 'pid_task');

% %Deadline overrun handler
% ttCreateHandler('handler_task', 1, 'handler_code');
% ttAttachDLHandler('pid_task', 'handler_task');


