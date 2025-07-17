REM 콘솔창에서 명령어 출력 숨김
@echo off
REM 변수/경로 등의 기능을 안전하게 로컬화 또한 Call 과같은 언어사용을 위함
setlocal enableextensions
REM 현재파일(copy.bat) 파일의 경로를 basedir 에 저장
set BASEDIR=%~dp0
REM 콘솔창에 시작알림용
echo ===================================
echo [Copy Script] 시작됨
echo ===================================

REM Debug & Release 구성 복사(아래 정의된서브루틴사용 (함수정의부) call없으면 goto로 사용되서 점프해버림(해당부분까지 continue된다는 의미))
call :CopyConfig Debug
call :CopyConfig Release

REM 헤더 복사 (완전 초기화) 경로는 본인 프로젝트 경로로 설정바람
set HEADER_SRC=%BASEDIR%Engine\Header\*.*
set HEADER_DST=%BASEDIR%Reference\Header\
REM 파일의 헤더및 초기화 그리고 복사용도로 사용하게됨
echo - 헤더 초기화 및 복사
REM 헤더에 해당하는 대상폴더가 존재하면 하위폴더 포함해서 전부삭제 exist
if exist "%HEADER_DST%" (
    REM readDir /s 하위폴더포함 /q 확인생략
    rd /s /q "%HEADER_DST%"
)
REM 해당위치에 폴더를 다시 생성함
mkdir "%HEADER_DST%" >nul 2>&1
REM SRC에 있던 모든 파일들을 DST로 전부 복사 덮어쓰기
xcopy /y "%HEADER_SRC%" "%HEADER_DST%" >nul
REM 완료 알림
echo ===================================
echo [Copy Script] 완료됨
echo ===================================

REM 완료되면 알림
powershell -command "Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('복사 완료됨! 모든 구성 반영됨.','Copy.bat')"

exit /b 0

REM 위에서 정의한 copyconfig의 구현부
:CopyConfig
REM 호출시 전달받은 이름을 config에 저장(함수몸체라고 생각하면됨 지역변수처럼사용됨)
set CONFIG=%1
REM 콘솔창에 띄움
echo - 복사 구성: %CONFIG%
REM SRC 복사할 원본위치경로저장 DST 복사될 위치 저장
set DLL_SRC=%BASEDIR%Engine\Bin\%CONFIG%\Engine.dll
set LIB_SRC=%BASEDIR%Engine\Bin\%CONFIG%\Engine.lib
set DLL_DST=%BASEDIR%Client\Bin\%CONFIG%\
set LIB_DST=%BASEDIR%Reference\Library\%CONFIG%\

REM DLL과 LIB만 삭제하고 폴더는 유지
if exist "%DLL_DST%Engine.dll" (
    del /f /q "%DLL_DST%Engine.dll"
)
if exist "%LIB_DST%Engine.lib" (
    del /f /q "%LIB_DST%Engine.lib"
)

REM 폴더가 없으면 생성
if not exist "%DLL_DST%" (
    mkdir "%DLL_DST%" >nul 2>&1
)
if not exist "%LIB_DST%" (
    mkdir "%LIB_DST%" >nul 2>&1
)

REM DLL 복사
if exist "%DLL_SRC%" (
    echo   → DLL 복사 중...
    xcopy /y "%DLL_SRC%" "%DLL_DST%" >nul
) else (
    echo   [경고] DLL 없음: %DLL_SRC%
)

REM LIB 복사
if exist "%LIB_SRC%" (
    echo   → LIB 복사 중...
    xcopy /y "%LIB_SRC%" "%LIB_DST%" >nul
) else (
    echo   [경고] LIB 없음: %LIB_SRC%
)

exit /b 0
