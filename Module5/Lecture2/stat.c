#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct stat sb;

    stat(argv[1], &sb);
    
    printf("Inode #: %ld\n", sb.st_ino);
    printf("Size (Bytes): %ld\n", sb.st_size);
    printf("File? %d\n", S_ISREG(sb.st_mode));
    printf("Directory? %d\n", S_ISDIR(sb.st_mode));

    return 0;
}