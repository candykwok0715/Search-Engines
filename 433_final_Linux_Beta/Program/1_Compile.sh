#!/bin/bash
g++ stem.cpp -c -w
g++ IInvFile.cpp -c -w
g++ InvFileMake.cpp -c -w
g++ DocLenMake.cpp -c -w
g++ Retrieval.cpp -c -w
g++ -o ../InvFileMake InvFileMake.o IInvFile.o stem.o -w
g++ -o ../DocLenMake DocLenMake.o IInvFile.o stem.o -w
g++ -o ../Retrieval Retrieval.o IInvFile.o stem.o -w
javac -d ../ InvFileTrim.java 
cd ../
