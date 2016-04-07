#!/bin/bash
## test.sh for  in /home/querat_g/tmp/cpp_arcade/games/snake
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Fri Apr  1 16:43:04 2016 querat_g
## Last update Fri Apr  1 18:38:01 2016 querat_g
##

make test

echo -ne "\x1\x0" | valgrind ./a.out | hexdump
