function [ exectime, data ] = task_C_code_mon( segment, data )

global glbData;

switch segment
    case 1
        ttEnterMonitor('mon');
        exectime = 0;
    case 2
        exectime = 10;
    case 3
        ttExitMonitor('mon');
        exectime = 0;
    case 4
        exectime = 40;
    case 5
        exectime = -1;   
end

