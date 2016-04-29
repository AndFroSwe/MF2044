function [exectime, data] = dl_miss_code(seg, data)

% find the name of the invoking task
task = sscanf(ttGetInvoker, 'DLtimer:%s');
switch seg
case 1
    % print the error message 
    disp([task ' missed deadline at ' num2str(ttCurrentTime)]);

    if ~isempty(task)
        ttKillJob(task);    % kill the delayed job
    end
    
    exectime = 0.00001;
case 2
    exectime = -1;
end