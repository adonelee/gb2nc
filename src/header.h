#ifndef __header__
#define __header__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netcdf.h>

int count_lines(FILE *fd) {
    int count = 0;
    char buf;

    while ((buf = fgetc(fd)) != EOF) {
        if (buf=='\n') count++;
    }

    return count;
}


char *remove_file_extension(char *file) {
    char *buf;
    buf = (char *)malloc(sizeof(char) * 64);
    memset(buf, 0, sizeof(char) * 64);

    strcpy(buf, file);

    /*remove extension*/
    char *dot = strrchr(buf, '.');
    if (dot == NULL) {
        printf("file has no extension\n");
    } else {
        *dot = '\0';
    }
    
    return buf;
}

char *remove_file_path(char *fname) {
    char *buf = strrchr(fname, '/');
    if (buf == NULL) {
        return NULL;
    }
    return strdup(buf + 1);
}

#endif