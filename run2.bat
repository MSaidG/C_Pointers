@echo off

taskkill /IM main2.exe /F
g++ -w -g pointers2.cpp -o main2.exe

start main2.exe