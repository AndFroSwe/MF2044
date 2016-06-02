function [ exectime, data ] = task_B_code_mon( segment, data )

global glbData;

switch segment
    case 1
        exectime = 70;
    case 2
        ttEnterMonitor('mon');
        exectime = 0;
    case 3
        exectime = 10;
    case 4
        ttExitMonitor('mon');
        exectime = -1;   
end

