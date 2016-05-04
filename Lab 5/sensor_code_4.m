function [ exectime, data ] = sensor_code_4( segment, data )
%PID_CODE Summary of this function goes here
%   Detailed explanation goes here
global message;

switch segment
    case 1
        r = ttAnalogIn(data.rChan);
        y = ttAnalogIn(data.yChan);
        
        message = [r y];
        exectime = data.wcet_sens;
        
    case 2
         ttTryPost('mail', message);
         
         exectime = 0;
    case 3
        exectime = -1;
end

