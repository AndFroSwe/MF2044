function [ exectime, data ] = pid_code3( segment, data )

switch segment
    case 1
        exectime = data.wcet3;
    case 2       
        exectime = -1;   
end

