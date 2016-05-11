function node_init_act(inp)

clc
choice = inp;
order = [1 2];
disp(order);
prio = {'prioDM', 'prioFP', 'prioEDF'};
disp(prio{choice});

ttInitKernel(prio{choice}); %Initiate scheduling mode

% Task parameters
starttimes = [0 0];
periods = [0.005 0.005];
tasknames = {'sens_task', 'act_task'};
codefcn = {'sens_code', 'act_code'};

% Create the tasks
for i = 1:length(tasknames)
    data.wcet = 0.001; % execution time
    data.uChan = 1;
    data.yChan = 1;
    data.u = 0;
    data.h = periods(i);

    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
    ttSetPriority(order(i), tasknames{i});
end




