function [ exectime, data ] = pid_code1( segment, data )

global glbData;

switch segment
    case 1
        glbData.x = 1;
        exectime = data.wcet1;
        
    case 2
        glbData.y = 1;
        exectime = data.wcet2;
    case 3
        summation = glbData.x + glbData.y;
        ttAnalogOut(1, summation);
        
        exectime = -1;   
end

