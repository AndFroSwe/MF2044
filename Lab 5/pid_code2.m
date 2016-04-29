function [ exectime, data ] = pid_code2( segment, data )

global glbData;

switch segment
    case 1
        glbData.x = 2;
        exectime = data.wcet1;
        
    case 2
        glbData.y = 2;
        exectime = data.wcet2;
    case 3
        summation = glbData.x + glbData.y;
        ttAnalogOut(2, summation);
        
        exectime = -1;   
end

