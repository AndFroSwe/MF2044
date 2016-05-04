function [ exectime, data ] = act_code( segment, data )

switch segment
    case 1
        msg = ttGetMsg;
        if isempty(msg)
            exectime = -1;
        else
            data.u = msg(2);
            fprintf('act_node recieved u: %f \n', data.u)
       
            exectime = data.wcet;
            
        end
        
    case 2
        ttAnalogOut(data.uChan, data.u);
        exectime = -1;
end

