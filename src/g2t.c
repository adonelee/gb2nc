#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        printf("Usage : a.out [gb2 file abs path] [savd path]");
        return 1;
    }

    char command[128] = "";
    char *kw_command = "kwgrib2 ";
    char *txt_opt = "-text ";

    char *fname = strrchr(argv[1], '/');
    char *filename = strchr(fname, '.');
    char *path = argv[2];  //   /home/ncdc/lee/tbin

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
//command = kwgrib2 g128_v070_ergl_unis_h009.2023121218.gb2 -text .gb2/home/ncdc/lee/tbin/.gb2.txt
    system(command);
    
    return 0;
}