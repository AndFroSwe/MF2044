function [exectime, data] = handler_code(segment, data)
%HANDLER_CODE Summary of this function goes here
%   Detailed explanation goes here
switch segment
    case 1
        disp('Task overrun!!!');
        exectime = 0.001;
    case 2
        exectime = -1;
end

