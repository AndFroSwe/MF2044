disp('Adding Truetime path');
path = 'C:\Users\Public\Documents\MATLAB\truetime-2.0\';
cd(path)
cd kernel
setenv('TTKERNEL',pwd)
cd matlab
cd help
addpath(pwd)
cd ..
addpath(pwd)
cd ..
addpath(pwd)
cd ..
disp('Truetime path added!');