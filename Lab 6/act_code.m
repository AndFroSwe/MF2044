function [ exectime, data ] = act_code( segment, data )
%PID_CODE Summary of this function goes here
%   Detailed explanation goes here

switch segment
    case 1
        data.u = ttGetMsg;
        if isempty(data.u)
            exectime = -1
        else
            exectime = data.wcet;
        end

    case 2
        ttAnalogOut(data.uChan, data.u);
        exectime = -1;
end

