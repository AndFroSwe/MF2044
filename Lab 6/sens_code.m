function [ exectime, data ] = sens_code( segment, data )

switch segment
    case 1
        data.y = ttAnalogIn(data.yChan);
        data.msgId = 2;
        
        exectime = data.wcet;
    case 2
        ttSendMsg(3, [data.msgId, data.y], 40);
        fprintf('sens_node sent y: %f \n', data.y)
        
        exectime = -1;
end