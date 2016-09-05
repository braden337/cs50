#### How to install the CS50 library on a Mac

```bash
$ gcc -c -ggdb -std=c99 cs50.c -o cs50.o
$ ar rcs libcs50.a cs50.o
$ rm cs50.o
$ chmod 0644 cs50.h libcs50.a
$ cp cs50.h /usr/local/include
$ cp libcs50.a /usr/local/lib
```