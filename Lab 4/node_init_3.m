function node_init(inp)
clc
choice = inp
order = [2 3 4];
disp(order)
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [0 0 0];
periods = [0.006 0.005 0.004];
tasknames = {'pid_task1', 'pid_task2', 'pid_task3'};
codefcn = 'pid_code_3';

%Deadline overrun handler
ttCreateHandler('dl_miss_task', 1, 'dl_miss_code');

% Create the three tasks
for i = 1:3
    data.wcet = 0.0016; % execution time
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
    data.yChan = i+1;
    data.uChan = i;
    data.late = 0;

    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn, data);
    if strcmp(prio{choice}, 'prioFP')
        disp('hajj hajj')
        ttSetPriority(order(i), tasknames{i});
    end
    ttCreateLog(tasknames{i},1,['response' num2str(i)],1000)
    % attach deadline overrun handler
    ttAttachDLHandler(tasknames{i}, 'dl_miss_task');
end




