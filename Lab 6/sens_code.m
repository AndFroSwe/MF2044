function [ exectime, data ] = sens_code( segment, data )

switch segment
    case 1
        data.y = ttAnalogIn(data.yChan);

        exectime = data.wcet;
    case 2
        ttSendMsg(3, data.y ,32);
        
        exectime = -1;
end
