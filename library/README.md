# CS50 Library

Run these commands to install the CS50 library on
a Mac.

```shell
gcc -c -ggdb -std=c99 cs50.c -o cs50.o
ar rcs libcs50.a cs50.o
rm cs50.o
chmod 0644 cs50.h libcs50.a
cp cs50.h /usr/local/include
cp libcs50.a /usr/local/lib
```

Copy the makefile to the directory you're working in,
or preferably export these environment variables in your .zshrc
(or .bashrc, .bash_profile, .profile) file.

```shell
export CC=clang
export CFLAGS="-O0 -std=c11 -Wall -Werror -Wshadow"
export LDLIBS="-lcs50 -lm"
```