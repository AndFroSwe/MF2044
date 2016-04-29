function [ exectime, data ] = pid_code2( segment, data )

global glbData;

switch segment
    case 1
        ttTake('sem1');
        exectime = 0;
    case 2
        glbData.x = 2;
        exectime = data.wcet1;
        
    case 3
        glbData.y = 2;
        exectime = data.wcet2;
    case 4 
        summation = glbData.x + glbData.y;
        ttAnalogOut(2, summation);
        exectime = 0;
    case 5
        ttGive('sem1');
        exectime = -1;   
end

