#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        printf("Usage : a.out [gb2 file] [path]");
        return 1;
    }

    char command[128] = "";
    char *kw_command = "kwgrib2 ";
    char *txt_opt = "-text ";

    char *fname = argv[1];
    char *filename = strrchr(strrchr(fname, '.'), '/');
    char *path = argv[2];

    char out_path[64];
    strcat(out_path, path);
    strcat(out_path, "/");
    strcat(out_path, filename);
    strcat(out_path, ".txt");

    strcat(command, kw_command);
    strcat(command, fname);
    strcat(command, " ");
    strcat(command, txt_opt);
    strcat(command, filename);
    strcat(command, out_path);

    printf("command = %s\n", command);

    system(command);
    
    return 0;
}