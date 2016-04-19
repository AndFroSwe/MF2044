function [  ] = runSimAndScale( fileName )
%RUNSIMANDSCALE Summary of this function goes here
%   Detailed explanation goes here
sim (fileName)

% find all scope blocks as MATLAB figures:
set(0, 'showhiddenhandles', 'on')
scope = findobj(0, 'Tag', 'SIMULINK_SIMSCOPE_FIGURE');
for i=1:length(scope)
  % this is the callback of the "autoscale" button:
  simscope('ScopeBar', 'ActionIcon', 'Find', scope(i))
end
set(0, 'showhiddenhandles', 'off');

end

