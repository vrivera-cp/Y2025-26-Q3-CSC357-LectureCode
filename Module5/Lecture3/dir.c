#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    DIR *dir = opendir(argv[1]);

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        printf("%ld %s\n", dirent->d_ino, dirent->d_name);
        
        if (dirent->d_type == DT_DIR) {
            printf(" DIRECTORY!\n");
        }
    }

    closedir(dir);

    return 0;
}