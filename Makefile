#Cleanup for Project0 files and to make them as well
all: project0.c
  gcc -g -Wall -o project0 project0.c

clean: 
  rm -f project0
