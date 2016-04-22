function [ exectime, data ] = pid_code( segment, data )
%PID_CODE Summary of this function goes here
%   Detailed explanation goes here

switch segment
    case 1
        r = ttAnalogIn(data.rChan);
        y = ttAnalogIn(data.yChan);
        data = pidcalc(data, r, y);
        
        exectime = 0.0013;
        
    case 2
        ttAnalogOut(data.uChan, data.u);
        exectime = -1;
end

