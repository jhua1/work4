#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void main(){
  
  struct stat p;
  int test = stat("statStuff.c",&p);

  printf("file size: %ld\n", p.st_size);
  printf("file mode: %d\n", p.st_mode);
  printf("last change to file: %s\n", asctime(gmtime(&p.st_atime)));
}
