function [ exectime, data ] = task_A_code_mon( segment, data )

global glbData;

switch segment
    case 1
        ttEnterMonitor('mon');
        exectime = 0;
    case 2
        exectime = 10;
    case 3       
        ttExitMonitor('mon');
        exectime = -1;   
end

