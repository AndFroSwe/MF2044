function node_init_1(Ts)
% Choose prio scheme
prio = {'prioDM', 'prioFP', 'prioEDF'};
% choice = 1;
% disp(prio{choice});
ttInitKernel('prioDM'); %Initiate scheduling mode

% Task parameters
starttime = 0;
period = Ts;
taskname = 'pid_task';
codefcn = 'pid_code_1';

% Setup PID
data.wcet = 0.0013;% Execution time
data.K = 1;
data.Ti = 0.12;
data.Td = 0.049;
data.beta = 0.5;
data.N = 10;
data.h = period;
data.u = 0;
data.Iold = 0;
data.Dold = 0;
data.yold = 0;
data.rChan = 1;
data.yChan = 2;
data.uChan = 1;
data.late = 0;

ttCreatePeriodicTask(taskname, starttime, period, codefcn, data);
ttSetPriority(1, taskname);


