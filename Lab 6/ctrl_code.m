function [ exectime, data ] = ctrl_code( segment, data )
switch segment
    case 1
        %initiate parameter values
        data.r = '';
        data.y = '';
        data.msgId = 3;
%         msg = ['r', 'y'];
        msg = ttGetMsg;
        if isempty(msg) %Exit if empty
            exectime = -1;
        else
            % loop until queue is empty
            while ~(isempty(msg))            
                if (msg(1) == 1) && (isempty(data.r)) % read r
                    data.r = msg(2);
                elseif (msg(1) == 2) && (isempty(data.y)) % read y
                    data.y = msg(2);
                end       
                msg = ttGetMsg; % get new message
            end
            % calculate pid output
            data = pidcalc(data, data.r, data.y);
            exectime = data.wcet;
        end

    case 2
        ttAnalogOut(data.uChan, data.u);
        ttSendMsg(2, [data.msgId, data.u], 40, 1);
        exectime = -1;
end

