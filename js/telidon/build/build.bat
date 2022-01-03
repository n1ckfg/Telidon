@echo off

cd /D %~dp0

set BUILD_TARGET=..\naplps.js
del %BUILD_TARGET%

copy /b naplps-main.js+naplps-decoder.js+naplps-encoder.js %BUILD_TARGET%

@pause