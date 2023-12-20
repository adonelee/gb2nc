#include "header.h"

char *set_outpath(char *path, char *filename) {
    char *buf;
    buf = (char *)malloc(sizeof(char) * 64);
    memset(buf, 0, sizeof(char) * 64);

    strcat(buf, path);
    strcat(buf, filename);
    strcat(buf, ".nc"); 

    return buf;
}

char *set_gb2tonc4_command(char *fname, char *filename, char *out_path) {
    char *buf;
    buf = (char *)malloc(sizeof(char) * 256);
    memset(buf, 0, sizeof(char) * 256);

    strcat(buf, "kwgrib2 -nc4 ");
    strcat(buf, fname);
    strcat(buf, " ");
    strcat(buf, "-netcdf ");
    strcat(buf, out_path);
    strcat(buf, " > /home/ncdc/lee/tbin/");
    strcat(buf, filename);
    strcat(buf, "_flag.txt");

    return buf;
}

int main(int argc, char *argv[]) {
    printf("app start\n");
    
    if (argc != 3) {
        printf("Usage : gb2nc4 [gb2 file abs path] [savd path]");
        return 1;
    }
    
    char *command, *out_path;
    char *path = argv[2];  //   /home/ncdc/lee/tbin
    /*fname is fileanme contains absolute path*/
    char *fname;
    /*file is fileanme removed path, contains extension*/
    char *file;
    /*it is fileanme removed path, extesion*/
    char *filename;
    
    /* set file attributes */
    fname = argv[1];
    file = remove_file_path(fname);
    if (file == NULL) {
        printf("not absolute path\n");
        printf("Usage : gb2nc4 [gb2 file abs path] [savd path]\n");
        return 1;
    }
    filename = remove_file_extension(file);
    
    /* set out path and output name */
    out_path = set_outpath(path, filename);
    
    /* set command */
    command = set_gb2tonc4_command(fname, filename, out_path);
    
    printf("%s\n", command);
    
    /* execute system command */
    system(command);
    
    free(file);
    printf("free(file);");
    free(filename);
    printf("free(filename);");
    free(out_path);
    printf("free(out_path);");
    free(command);
    printf("free(command);");
    
    printf("app finish\n");
    return 0;
}