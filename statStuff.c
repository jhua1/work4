#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void main(){
  
  struct stat *p = (struct stat*)malloc(sizeof(struct stat));
  int test = stat("statStuff.c",p);

  printf("statStuff.c mode: %lu\n",(unsigned long)p->st_atime);

}
