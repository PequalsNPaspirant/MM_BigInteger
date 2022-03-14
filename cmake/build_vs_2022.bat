@ECHO OFF
SETLOCAL

set CLEANBUILD=%1

IF /I "%CLEANBUILD%"=="clean" (
	echo.removing old build contents...
	del /S /Q "build_vs_2022\*.*"
)

cmake -H. -Bbuild_vs_2022 -G "Visual Studio 17 2022" -A x64

cmake --build build_vs_2022 --config RelWithDebInfo
