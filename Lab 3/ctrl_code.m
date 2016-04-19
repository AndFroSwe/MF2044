function [ exectime, data ] = ctrl_code( segment, data )
%CTRL_CODE Summary of this function goes here
%   Detailed explanation goes here

switch segment
    case 1
        targetPos = ttAnalogIn(1);
        motorPos = ttAnalogIn(2);
        
        data.motorVel = data.K * (targetPos - motorPos);
        exectime = rand * data.wcet;
        
    case 2
        ttAnalogOut(1, data.motorVel);
        exectime = -1;
end

