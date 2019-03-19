# algorithm training
Codes for practicing algorithm and solving problems in [Uva Online Judge](https://uva.onlinejudge.org/index.php).

## Environment setup for C/C++

### 1. Windows

install [MinGW](http://www.mingw.org/) (short for Minimalist GNU for Windows) from its installation manager,  
then add executable path (eg. `C:\MinGW\bin`) into system path.

(`note`: Rebooting might be required to reload the path environment variable)

### 2. Linux (Ubuntu)

```bash
$ sudo apt install build-essential
```

## Build C/C++ program

build C program
```bash
$ gcc solution.c -o solution.exe
```

build C++ program
```bash
$ g++ solution.cpp -o solution.exe
```