@ECHO Installerar om Truetype
@ECHO.  

SET src_folder=C:\Users\Public\Documents\MATLAB
SET tar_folder=C:\Users\Public\Documents\MATLAB\_old
SET "curpath=%cd%"
SET "truetime=%curpath%\truetime-2.0

mkdir "C:%homepath%\Documents\MATLAB\"
COPY "%curpath%\init_truetime.m" "C:%homepath%\Documents\MATLAB\startup.m"

RD /S /Q %tar_folder%

MD "C:\Users\Public\Documents\MATLAB\truetime-2.0\"

robocopy %src_folder% %tar_folder% /MOV /E
robocopy "%truetime%" "C:\Users\Public\Documents\MATLAB\truetime-2.0" /E

::@PAUSE

