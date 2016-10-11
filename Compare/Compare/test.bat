set PROGRAM="%~1"

rem �� ����� 1 ��������
%PROGRAM% not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem ����������� ������� ��� �����
%PROGRAM% not_found.txt
if NOT ERRORLEVEL 1 goto err

rem ��������� ��������� ���� ������ ��������� �� ������ ������
%PROGRAM% difference_in_second_line1.txt difference_in_second_line2.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% difference_in_second_line2.txt difference_in_second_line1.txt
if NOT ERRORLEVEL 1 goto err

rem ��������� ���� ������, ����� � ������ ����� ��� ������, � �� ������ ���
%PROGRAM% three_lines.txt two_lines.txt                      
if NOT ERRORLEVEL 1 goto err

%PROGRAM% two_lines.txt three_lines.txt                      
if NOT ERRORLEVEL 1 goto err

rem ��������� �� ������� ����� � ����� �����
%PROGRAM% not_empty.txt not_empty.txt
if ERRORLEVEL 1 goto err

rem ��������� ������� ����� � �� ������
%PROGRAM% empty.txt not_empty.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1