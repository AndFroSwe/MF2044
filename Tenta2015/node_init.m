function node_init(inp)

% define shared resource
global glbData;

clc
choice = 1;
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [1 1 0];
periods = [100 150 300];
tasknames = {'task_A', 'task_B', 'task_C'};
codefcn = {'task_A_code', 'task_B_code', 'task_C_code'};

% initiate semaphore
ttCreateSemaphore('sem', 1, 1);

% %Deadline overrun handler
% ttCreateHandler('dl_miss_task', 1, 'dl_miss_code');

data = [];
% Create the three tasks
for i = 1:length(tasknames)
    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
end




