function [ exectime, data ] = task_A_code( segment, data )

global glbData;

switch segment
    case 1
        ttEnterMonitor('sem');
        exectime = 0;
    case 2
        exectime = 10;
    case 3       
        ttGive('sem');
        exectime = -1;   
end

