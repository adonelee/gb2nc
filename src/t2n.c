#include "header.h"

int netcdf_put_var(int ncid, FILE *fd, int xdim_len, int ydim_len) {
    int x_dimid, y_dimid;
    char description[64];

    // Define dimensions
    if (nc_def_dim(ncid, x_dimid, xdim_len, &x_dimid) != NC_NOERR ||
        nc_def_dim(ncid, y_dimid, ydim_len, &y_dimid) != NC_NOERR) {
        fprintf(stderr, "Error defining dimensions.\n");
        nc_close(ncid);
        return 1;
    }

    int var_len = xdim_len * ydim_len;
    for (int i = 0; i < var_len; i++) {
        
    }

    return 0;
}


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
    
    /* out path*/
    char out_path[128];
    char *path = argv[3];
    strcat(out_path, path);
    strcat(out_path, filename);
    strcat(out_path, ".nc");

    
    //
    /* file open */
    FILE *data_fd, *flag_fd;
    char buf[32];

    data_fd = fopen(fname, "rt");
    flag_fd = fopen(flagname, "rt");


    int ncid;

    /* determine dimension length */
    fgets

    // Create a new NetCDF file
    if (nc_create(out_path, NC_CLOBBER, &ncid) != NC_NOERR) {
        fprintf(stderr, "Error creating NetCDF file.\n");
        return 1;
    }



    fclose(data_fd);
    fclose(flag_fd);
    printf("app end\n");

    return 0;
}