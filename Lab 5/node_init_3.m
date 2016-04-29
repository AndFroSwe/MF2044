function node_init(inp)

% define shared resource
global glbData;
glbData.x = 0;
glbData.y = 0;

clc
choice = inp
order = [3 1 2];
disp(order)
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [0 0.5 0.8];
periods = [3 3 3];
tasknames = {'pid_task1', 'pid_task2', 'pid_task3'};
codefcn = {'pid_code1_m', 'pid_code2_m','pid_code3_m'};

% initiate semaphore
ttCreateMonitor('mon1');


% Create the three tasks
for i = 1:3
    data.wcet1 = 0.6; % execution time
    data.wcet2 = 0.4; % execution time
    data.wcet3 = 0.5; % execution time
    

    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
    if strcmp(prio{choice}, 'prioFP')
        disp('hajj hajj')
        ttSetPriority(order(i), tasknames{i});
    end
end




