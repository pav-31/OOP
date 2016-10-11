set PROGRAM="%~1"

rem на входе 1 аргумент
%PROGRAM% not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem некорректно введено имя файла
%PROGRAM% not_found.txt
if NOT ERRORLEVEL 1 goto err

rem проверяем сравнение двух файлов различных во второй строке
%PROGRAM% difference_in_second_line1.txt difference_in_second_line2.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% difference_in_second_line2.txt difference_in_second_line1.txt
if NOT ERRORLEVEL 1 goto err

rem сравнение двух файлов, когда в первом файле три строки, а во втором две
%PROGRAM% three_lines.txt two_lines.txt                      
if NOT ERRORLEVEL 1 goto err

%PROGRAM% two_lines.txt three_lines.txt                      
if NOT ERRORLEVEL 1 goto err

rem сравнение не пустого файла с самим собой
%PROGRAM% not_empty.txt not_empty.txt
if ERRORLEVEL 1 goto err

rem сравнение пустого файла с не пустым
%PROGRAM% empty.txt not_empty.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1