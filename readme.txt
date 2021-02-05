

Simple operations with file


to compile:

g++ *.cpp -o out

to run:

if file in current folder just type name of file with extension:
./out
test.txt

out.exe
test.txt

if file in another directory, then name of file and path to file:
./out
write the name of the file: /home/dima/Documents/test.txt

program can take optional arguments: nameOfFile and r
for example this command will create or open file test.txt
./out test.txt
and this command will create and replace current file (if it already exists) test.txt
./out test.txt r


