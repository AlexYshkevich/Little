#!/bin/bash

if ! [ -d out ]; then
	mkdir out
fi

rm out/* -f

if [ -f start.exe ]; then
	rm start.exe -f 
fi

g++ *.cpp -o start.exe --std=c++11

if [ $? != 0 ]; then
	exit 1
fi

sync 

if [ $? != 0 ]; then
	exit 2
fi

if [[ $1 = "-r" ]]; then
	echo RUN!
	./start.exe files/test1.dat files/test1.txt
fi





