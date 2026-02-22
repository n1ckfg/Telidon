@echo off

cd %~dp0

start http://127.0.0.1:8080

http-server

@pause