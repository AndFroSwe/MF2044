function [ exectime, data ] = ref_code( segment, data )
switch segment
    case 1
        r = ttGetMsg;
        if isempty(r)
            exectime = -1
        else
            data.u = r;
            exectime = data.wcet;
        end
    case 2
        ttAnalogOut(data.uChan, data.u);
        %ttSendMsg(3, data.u, 32);
        exectime = -1;
end

