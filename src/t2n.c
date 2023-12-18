#include "header.h"

int main(int argc, char *argv[]) {
    int i;

    if (argc != 4) {
        printf("Usage : a.out [text file abs path] [flag file abs path] [savd path]");
        return 1;
    }

    /* data file */
    char *fname = argv[1];
    char *file = strrchr(fname, '/');
    file++;

    /* remove format in filename */
    char tmp[64];
    strcpy(tmp, file);
    char *dot = strrchr(tmp, '.');
    if (dot != NULL) {
        *dot = '\0';
    }
    char filename[64];
    strcpy(filename, tmp);

    /* flag file */
    char *flagname = argv[2];
    
    
    /* file open */
    FILE *data_fd, *flag_fd;

    data_fd = fopen(fname, "rt");
    flag_fd = fopen(flagname, "rt");

    fclose(data_fd);
    fclose(flag_fd);

    return 0;
}