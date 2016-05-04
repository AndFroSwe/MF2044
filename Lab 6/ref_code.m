function [ exectime, data ] = ref_code( segment, data )
switch segment
    case 1
        r = ttAnalogIn(data.rChan);
        data.u = r;
        exectime = data.wcet;
    case 2
        ttAnalogOut(data.uChan, data.u);
        ttSendMsg(3, data.u, 32);
        exectime = -1;
end

