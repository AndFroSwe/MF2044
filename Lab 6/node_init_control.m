function node_init_control(inp)

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
tasknames = {'ctrl_task'};
codefcn = {'ctrl_code'};


% Create the tasks
for i = 1:length(tasknames)
    data.r = 0;
    data.y = 0;
    data.wcet = 0.0015; % execution time
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

    
    ttCreatePeriodicTask(tasknames{i}, starttimes(i), periods(i), codefcn{i}, data);
    ttSetPriority(order(i), tasknames{i});
end




