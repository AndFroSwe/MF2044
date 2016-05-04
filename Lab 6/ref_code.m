function [ exectime, data ] = ref_code( segment, data )
switch segment
    case 1
        r = ttAnalogIn(data.rChan);
        data.r = r;
        data.msgId = 1;
        exectime = data.wcet;
    case 2
        ttAnalogOut(data.uChan, data.r);
        ttSendMsg(3, [data.msgId, data.r], 40);
        %fprintf('ref_code sent r: %f \n', data.r)
        exectime = -1;
end

