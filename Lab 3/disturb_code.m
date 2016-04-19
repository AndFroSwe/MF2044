function [exectime, data] = disturb_code(segment, data)
switch segment
    case 1
        exectime = 0.1; %Disturbance time
    case 2
        exectime = -1;
end

