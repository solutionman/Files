
Simple operations with file

to compile:

g++ *.cpp -o out

to run:

if file in current folder just type name of file with extension:
./out test.txt

out.exe test.txt

if file in another directory, then name of file and path to file:
./out /home/dima/Documents/test.txt

program can take optional arguments: r or o
this command will create and replace current file (if it already exists) test.txt
./out test.txt r
and this command will open file test.txt for editing
./out test.txt o


