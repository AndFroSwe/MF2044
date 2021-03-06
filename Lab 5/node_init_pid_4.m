function node_init_pid_4(inp)
clc
global message;

prio = 'prioFP';

ttInitKernel(prio); %Initiate scheduling mode

% Task parameters
starttimes = [0 0];
periods = [0.005 0.005];
order = [2 1];
tasknames = {'sensor_task', 'control_task'};
codefcn = {'sensor_code_4', 'control_code_4'};

% intialize message queue
ttCreateMailbox('mail', 1);

% Create the three tasks
for i = 1:length(tasknames)
    data.wcet_sens = 0.001; % execution time
    data.wcet_cont = 0.001; % execution time   
    data.K = 1;
    data.Ti = 0.12;
    data.Td = 0.049;
    data.beta = 0.5;
    data.N = 10;
    data.h = periods(i);
    data.u = 0;
    data.Iold = 0;
    data.Dold = 0;
    data.yold = 0;
    data.rChan = 1;
    data.yChan = 2;
    data.uChan = 1;
    data.late = 0;
    
    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);    
    ttSetPriority(order(i), tasknames{i});
end




