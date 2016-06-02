function [ exectime, data ] = task_B_code( segment, data )

global glbData;

switch segment
    case 1
        exectime = 70;
    case 2
        ttEnterMonitor('sem');
        exectime = 0;
    case 3
        exectime = 10;
    case 4
        ttExitMonitor('sem');
        exectime = -1;   
end

