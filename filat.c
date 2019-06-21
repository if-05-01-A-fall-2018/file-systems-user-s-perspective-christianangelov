
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat attributes;
    if (argc != 2) {
        printf("path is missing");
        return -1;
    }
    int s = lstat(argv[1],&attributes);
    if(s != 0)
    {
        printf("ERROR");
        return -1;
    }
	printf("------------------------ %s --------------------\n",argv[1]);
	printf("File type               :");

	if(S_ISREG(attributes.st_mode)) printf("Regular File");
  else if(S_ISDIR(attributes.st_mode)) printf("Directory");
  else if(S_ISCHR(attributes.st_mode))printf("Character device");
  else if(S_ISBLK(attributes.st_mode))printf("Block device");
  else if(S_ISFIFO(attributes.st_mode))printf("FIFO (named pipe)");
  else if(S_ISLNK(attributes.st_mode))printf("Symbolic link");
	else printf("Socket");
	printf("\nAccess privileges       :");
    printf( (attributes.st_mode & S_IRUSR) ? "r" : "-");
    printf( (attributes.st_mode & S_IWUSR) ? "w" : "-");
    printf( (attributes.st_mode & S_IXUSR) ? "x" : "-");
    printf( (attributes.st_mode & S_IRGRP) ? "r" : "-");
    printf( (attributes.st_mode & S_IWGRP) ? "w" : "-");
    printf( (attributes.st_mode & S_IXGRP) ? "x" : "-");
    printf( (attributes.st_mode & S_IROTH) ? "r" : "-");
    printf( (attributes.st_mode & S_IWOTH) ? "w" : "-");
    printf( (attributes.st_mode & S_IXOTH) ? "x" : "-");

    printf("\ninode number            : %ld\n", (long) attributes.st_ino);
    printf("device number           : dev = %ld rdev = %ld\n",attributes.st_dev,attributes.st_rdev);
    printf("links count             : %ld\n",(long)attributes.st_nlink);
    printf("UID                     : %ld\n", (long) attributes.st_uid);
    printf("GID                     : %ld\n", (long) attributes.st_gid);
    printf("preferred I/O block size: %ld bytes\n", (long) attributes.st_blksize);
    printf("file size               : %lld bytes\n", (long long) attributes.st_size);
    printf("blocks allocated        : %lld\n", (long long) attributes.st_blocks);
    printf("last status change      : %s", ctime(&attributes.st_ctime));
    printf("last file access        : %s", ctime(&attributes.st_atime));
    printf("last inode change       : %s", ctime(&attributes.st_mtime));
   return 0;
}
