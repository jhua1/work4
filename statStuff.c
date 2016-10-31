#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

char *modeString(struct stat p){
  char *ret[9];
  strcat(ret,*(p.st_mode & S_IRUSR) ? "r":"-");
  strcat(ret,*(p.st_mode & S_IWUSR) ? "w":"-");
  strcat(ret,*(p.st_mode & S_IXUSR) ? "x":"-");

  strcat(ret,*(p.st_mode & S_IRGRP) ? "r":"-");
  strcat(ret,*(p.st_mode & S_IWGRP) ? "w":"-");
  strcat(ret,*(p.st_mode & S_IXGRP) ? "x":"-");

  strcat(ret,*(p.st_mode & S_IROTH) ? "r":"-");
  strcat(ret,*(p.st_mode & S_IWOTH) ? "w":"-");
  strcat(ret,*(p.st_mode & S_IXOTH) ? "x":"-");

  return ret;
}

void main(){
  
  struct stat p;
  int test = stat("statStuff.c",&p);

  int size = (int)p.st_size;
  printf("file size: %d GB |",(int)(size/pow(2,30)));
  size = size%((int)pow(2,30));
  printf(" %d MB |",(int)(size/pow(2,20)));
  size = size%((int)pow(2,20));
  printf(" %d KB |",(int)(size/pow(2,10)));
  size = size%((int)pow(2,10));
  printf(" %d B\n",(int)(size));

  printf("file mode: %o: %s\n",~S_IFMT&p.st_mode,modeString(p));

  printf("last change to file: %s\n", asctime(gmtime(&p.st_atime)));
}
