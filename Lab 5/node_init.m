function node_init(inp)

% define shared resource
global glbData;
glbData.x = 0;
glbData.y = 0;

clc
choice = inp
order = [3 1];
disp(order)
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [0 0.5];
periods = [3 3];
tasknames = {'pid_task1', 'pid_task2'};
codefcn = {'pid_code1', 'pid_code2'};

% initiate semaphore
ttCreateSemaphore('sem1', 1, 1);

% %Deadline overrun handler
% ttCreateHandler('dl_miss_task', 1, 'dl_miss_code');

% Create the three tasks
for i = 1:2
    data.wcet1 = 0.6; % execution time
    data.wcet2 = 0.4; % execution time

    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
    if strcmp(prio{choice}, 'prioFP')
        disp('hajj hajj')
        ttSetPriority(order(i), tasknames{i});
    end
%     ttCreateLog(tasknames{i},1,['response' num2str(i)],1000)
%     % attach deadline overrun handler
%     ttAttachDLHandler(tasknames{i}, 'dl_miss_task');
end




