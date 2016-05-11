function node_init_hmi(inp)

clc
choice = inp;
order = [1];
disp(order);
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [0];
periods = [0.005];
tasknames = {'ref_task'};
codefcn = {'ref_code'};




% Create the tasks
for i = 1:length(tasknames)
    data.wcet = 0.001; % execution time
    data.rChan = 1;
    data.uChan = 1;
    data.u = 0;
    data.h = periods(i);

    
    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
    ttSetPriority(order(i), tasknames{i});
end




