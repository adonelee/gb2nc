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

#endif