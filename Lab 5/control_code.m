function [ exectime, data ] = control_code( segment, data )
%PID_CODE Summary of this function goes here
%   Detailed explanation goes here
global message;

switch segment
    case 1
        ttFetch('mail');
        
        exectime = 0;
        
    case 2
        message = ttRetrieve('mail');
%         disp(message)
        r = message(1);
        y = message(2);
        data = pidcalc(data, r, y)

        exectime = data.wcet_cont;    
    case 3
        ttAnalogOut(data.uChan, data.u)
        
        exectime = -1;
end

