function [ exectime, data ] = task_C_code( segment, data )

global glbData;

switch segment
    case 1
        ttTake('sem');
        exectime = 0;
    case 2
        exectime = 10;
    case 3
        ttGive('sem');
        exectime = 0;
    case 4
        exectime = 40;
    case 5
        exectime = -1;   
end

