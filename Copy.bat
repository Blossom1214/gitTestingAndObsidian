REM �ܼ�â���� ��ɾ� ��� ����
@echo off
REM ����/��� ���� ����� �����ϰ� ����ȭ ���� Call ������ ������� ����
setlocal enableextensions
REM ��������(copy.bat) ������ ��θ� basedir �� ����
set BASEDIR=%~dp0
REM �ܼ�â�� ���۾˸���
echo ===================================
echo [Copy Script] ���۵�
echo ===================================

REM Debug & Release ���� ����(�Ʒ� ���ǵȼ����ƾ��� (�Լ����Ǻ�) call������ goto�� ���Ǽ� �����ع���(�ش�κб��� continue�ȴٴ� �ǹ�))
call :CopyConfig Debug
call :CopyConfig Release

REM ��� ���� (���� �ʱ�ȭ) ��δ� ���� ������Ʈ ��η� �����ٶ�
set HEADER_SRC=%BASEDIR%Engine\Header\*.*
set HEADER_DST=%BASEDIR%Reference\Header\
REM ������ ����� �ʱ�ȭ �׸��� ����뵵�� ����ϰԵ�
echo - ��� �ʱ�ȭ �� ����
REM ����� �ش��ϴ� ��������� �����ϸ� �������� �����ؼ� ���λ��� exist
if exist "%HEADER_DST%" (
    REM readDir /s ������������ /q Ȯ�λ���
    rd /s /q "%HEADER_DST%"
)
REM �ش���ġ�� ������ �ٽ� ������
mkdir "%HEADER_DST%" >nul 2>&1
REM SRC�� �ִ� ��� ���ϵ��� DST�� ���� ���� �����
xcopy /y "%HEADER_SRC%" "%HEADER_DST%" >nul
REM �Ϸ� �˸�
echo ===================================
echo [Copy Script] �Ϸ��
echo ===================================

REM �Ϸ�Ǹ� �˸�
powershell -command "Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('���� �Ϸ��! ��� ���� �ݿ���.','Copy.bat')"

exit /b 0

REM ������ ������ copyconfig�� ������
:CopyConfig
REM ȣ��� ���޹��� �̸��� config�� ����(�Լ���ü��� �����ϸ�� ��������ó������)
set CONFIG=%1
REM �ܼ�â�� ���
echo - ���� ����: %CONFIG%
REM SRC ������ ������ġ������� DST ����� ��ġ ����
set DLL_SRC=%BASEDIR%Engine\Bin\%CONFIG%\Engine.dll
set LIB_SRC=%BASEDIR%Engine\Bin\%CONFIG%\Engine.lib
set DLL_DST=%BASEDIR%Client\Bin\%CONFIG%\
set LIB_DST=%BASEDIR%Reference\Library\%CONFIG%\

REM DLL�� LIB�� �����ϰ� ������ ����
if exist "%DLL_DST%Engine.dll" (
    del /f /q "%DLL_DST%Engine.dll"
)
if exist "%LIB_DST%Engine.lib" (
    del /f /q "%LIB_DST%Engine.lib"
)

REM ������ ������ ����
if not exist "%DLL_DST%" (
    mkdir "%DLL_DST%" >nul 2>&1
)
if not exist "%LIB_DST%" (
    mkdir "%LIB_DST%" >nul 2>&1
)

REM DLL ����
if exist "%DLL_SRC%" (
    echo   �� DLL ���� ��...
    xcopy /y "%DLL_SRC%" "%DLL_DST%" >nul
) else (
    echo   [���] DLL ����: %DLL_SRC%
)

REM LIB ����
if exist "%LIB_SRC%" (
    echo   �� LIB ���� ��...
    xcopy /y "%LIB_SRC%" "%LIB_DST%" >nul
) else (
    echo   [���] LIB ����: %LIB_SRC%
)

exit /b 0
