@echo off

taskkill /IM main1.exe /F
g++ -w -g pointers1.cpp -o main1.exe

start main1.exe