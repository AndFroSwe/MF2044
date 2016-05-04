function [ exectime, data ] = control_code_4( segment, data )
%PID_CODE Summary of this function goes here
%   Detailed explanation goes here
global message;

switch segment
    case 1
        message = ttTryFetch('mail');
        if isempty(message)
            exectime = -1;
        else
            exectime = 0;
        end
        
    case 2
        r = message(1);
        y = message(2);
        data = pidcalc(data, r, y)

        exectime = data.wcet_cont;    
    case 3
        ttAnalogOut(data.uChan, data.u)
        
        exectime = -1;
end

