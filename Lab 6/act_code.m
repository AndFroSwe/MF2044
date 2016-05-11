function [ exectime, data ] = act_code( segment, data )

switch segment
    case 1
        msg = ttGetMsg;
        if isempty(msg)
            exectime = -1;
        else
            while ~(isempty(msg))
                data.u = msg(2);
%                 fprintf('act_node recieved u: %f \n', data.u)
                msg = ttGetMsg;
            end
            exectime = data.wcet;
        end
        
    case 2
        ttAnalogOut(data.uChan, data.u);
        exectime = -1;
end

