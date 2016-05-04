function [ exectime, data ] = ref_code( segment, data )
switch segment
    case 1
        y = 2;
        r = ttGetMsg;
        if isempty(r)
            exectime = -1
        else
            data = pidcalc(data, r, y);
            
            exectime = data.wcet;
        end
        
        

    case 2
        ttAnalogOut(data.uChan, data.u);
        ttSendMsg(2, data.u, 32);
        exectime = -1;
end

