#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX 1024
struct stat attributes;

int main(int argc, char const *argv[]) {

  char text[MAX];
  if(argc != 3){
    printf("not 3 args\n" );
    return 0;
  }
  printf("3 args given\n" );


  printf("opening file:" );
  int fd = open(argv[1], O_RDONLY);
  if(fd < 0){
    printf("\t\t\t\t fail \n" );
    return 0;
  }
  printf("\t\t\t\t success\n");


  printf("reading File: ");
  if(read(fd, text, sizeof(text)) < 0) printf("\t\tfail\n");
  else printf("\t\t\t\t success\n" );
  printf("\n");

  int index = -1;
  while(text[++index ] != '\0') printf("%c",text[index] );

  for (size_t i = index; i < MAX; i++) text[i] = ' ';
  printf("\nfinished writing\n");
  int fd2 = open(argv[2],O_WRONLY);
  printf("opening second file: " );
  if(fd2 < 0)
  {
    printf("\t\t\t File not found\n" );
    printf("Created file and wrote text\n" );
    fd2 = creat(argv[2], S_IWUSR| S_IRUSR | S_IRGRP | S_IROTH);
    fd2 = open(argv[2],O_WRONLY);
  }
  else{
    printf("\t\t\t success");
    printf("\nWriting content of first in second");
    if(write(fd2, text, sizeof(text))< 0) printf("\t fail\n" );
    else printf("\t success\n" );
  }
  close(fd2);
  return 0;
}
