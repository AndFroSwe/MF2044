function [ exectime, data ] = ctrl_code( segment, data )
switch segment
    case 1
        data.msgId = 3;
        msg = ['r', 'y'];
        while ~(isempty(msg)) %Empty queue
            msg = ttGetMsg;
           
            if isempty(msg) %Exit if empty
                exectime = -1;
            else
                disp(msg(1))
                
                if (msg(1) == 1) % read r
                    disp('r')
                    data.r = msg(2);
                    %fprintf('Ctrl_code recieved r: %f \n', data.r)
                
                elseif (msg(1) == 2) % read y
                    disp('y')
                    data.y = msg(2);
                    fprintf('Ctrl_code recieved y: %f \n', data.y)
                end       
                data = pidcalc(data, data.r, data.y);
                exectime = data.wcet;
            end
        end
                    
        
    case 2
        ttAnalogOut(data.uChan, data.u);
        ttSendMsg(2, [data.msgId, data.u], 40);
        fprintf('Ctrl_code sent u: %f \n', data.u)
        exectime = -1;
end

