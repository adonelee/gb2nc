#include "header.h"

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        printf("Usage : g2t [gb2 file abs path] [savd path]");
        return 1;
    }

    char command[128] = "";
    char *kw_command = "kwgrib2 ";
    char *txt_opt = "-text ";

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
    char *path = argv[2];  //   /home/ncdc/lee/tbin

    char out_path[64] = "";
    strcat(out_path, path);
    strcat(out_path, "/");
    strcat(out_path, filename);
    strcat(out_path, ".txt");

    strcat(command, kw_command);
    strcat(command, fname);
    strcat(command, " ");
    strcat(command, txt_opt);
    strcat(command, out_path);

    printf("command = %s\n", command);
// kwgrib2 /g128_v070_ergl_unis_h009.2023121218.gb2 -text .2023121218.gb2/home/ncdc/lee/tbin/.2023121218.gb2.txt
    system(command);
    
    return 0;
}