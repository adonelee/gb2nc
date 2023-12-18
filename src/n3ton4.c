#include <stdio.h>
#include <stdlib.h>
#include <netcdf.h>

#define IN_FILE "g128_v070_ergl_unis_h009.2023121218.nc3"
#define OUT_FILE "g128_v070_ergl_unis_h009.2023121218.nc"
#define VAR_LEN 107
#define LAT_LEN 1920
#define LON_LEN 2560

char *varname[VAR_LEN] = {
"ACPCP_surface",
"APCP_surface",
"CAPE_atmoscol",
"CB25_HeightfromgroundKFT",
"CB45_HeightfromgroundKFT",
"CDCON_entireatmosphere_consideredasasinglelayer_",
"CDLWS_surface",
"CDSWS_surface",
"CPRAT_surface",
"CSRATE_surface",
"CULWT_topofatmosphere",
"CUSWS_surface",
"CUSWT_topofatmosphere",
"CWC_canopy",
"DIST_surface",
"DLWS_surface",
"DPT_1_5maboveground",
"ESSA_surface",
"EVOS_surface",
"FOGFR_1_5maboveground",
"FRICE_surface",
"FRICV_0maboveground",
"HCDC_entireatmosphere_consideredasasinglelayer_",
"HFICE_surface",
"HFSFC_surface",
"HFSOIL_0_0mbelowground",
"HPBL_planetaryboundarylayer",
"HSTDV_surface",
"IHCCB_ICAOconvectivecloudbaselevel",
"IHCCT_ICAOconvectivecloudtoplevel",
"ILCCB_ICAOconvectivecloudbaselevel",
"ILCCT_ICAOconvectivecloudtoplevel",
"INSWT_topofatmosphere",
"LAND_surface",
"LCCA_entireatmosphere_consideredasasinglelayer_",
"LCDC_entireatmosphere_consideredasasinglelayer_",
"LHTFL_surface",
"LLRIB_10maboveground",
"LSPRATE_surface",
"LSSRATE_surface",
"MAXGUST_0maboveground",
"MCDC_entireatmosphere_consideredasasinglelayer_",
"N15QT_1_5maboveground",
"N15TL_1_5maboveground",
"N50MU_50maboveground",
"N50MV_50maboveground",
"NCPCP_surface",
"NDLWO_surface",
"NDNLW_surface",
"NDNSW_surface",
"OULWT_topofatmosphere",
"OUSWT_topofatmosphere",
"PCCB_convectivecloudbottomlevel",
"PCCT_convectivecloudtoplevel",
"PLCCB_convectivecloudbottomlevel",
"PLCCT_convectivecloudtoplevel",
"PRES_surface",
"PRMSL_meansealevel",
"PVIS5_0maboveground",
"RH_1_5maboveground",
"ROFL_surface",
"SFCR_surface",
"SHFLT_surface",
"SHFO_surface",
"SMCL_0_0_1mbelowground",
"SMCL_0_1_0_35mbelowground",
"SMCL_0_35_1mbelowground",
"SMCL_1_3mbelowground",
"SMLHF_surface",
"SNOAL_surface",
"SNOC_surface",
"SNOL_surface",
"SNOM_surface",
"SOILM_surface",
"SPFH_1_5maboveground",
"SROFL_surface",
"STABL_surface",
"SUBS_surface",
"SWDIF_10maboveground",
"SWDIR_10maboveground",
"TCAM_entireatmosphere_consideredasasinglelayer_",
"TCAR_entireatmosphere_consideredasasinglelayer_",
"TCTH_0maboveground",
"TDSWS_surface",
"TMAX_1_5maboveground",
"TMIN_1_5maboveground",
"TMOFS_surface",
"TMP_1_5maboveground",
"TMP_surface",
"TOMFS_surface",
"TPRATE_surface",
"TSOIL_0_0_1mbelowground",
"TSOIL_0_1_0_35mbelowground",
"TSOIL_0_35_1mbelowground",
"TSOIL_1_3mbelowground",
"UCAPE_surface",
"UGRD_10maboveground",
"UPCIN_surface",
"VGRD_10maboveground",
"VIS_1_5maboveground",
"WBFLH_0Cisotherm",
"WMEFO_surface",
"WMXBL_surface",
"XBLWS_20maboveground",
"XGWSS_20maboveground",
"YBLWS_20maboveground",
"YGWSS_20maboveground"
};

int main() {
    int in_ncid, out_ncid;  // NetCDF file IDs
    int in_varids[VAR_LEN], out_varids[VAR_LEN];  // Variable IDs
    int dimids[3];  // Dimension IDs (time, latitude, longitude)
    size_t dimlen[3];  // Dimension lengths
    nc_type vartype;  // Variable data type
    void *data[VAR_LEN];  // Data buffers for each variable

    int ret;

    // Open the existing NetCDF3 file
    ret = nc_open(IN_FILE, NC_NOWRITE, &in_ncid);
    if (ret != NC_NOERR) {
        fprintf(stderr, "Error opening NetCDF3 file.\n");
        fprintf(stderr, "ERROR MSG: %s\n", nc_strerror(ret));
        return 1;
    }

    // Get dimension lengths for time, latitude, and longitude
    ret = nc_inq_dimlen(in_ncid, nc_inq_dimid(in_ncid, "time", &dimids[0]), &dimlen[0]);
    ret |= nc_inq_dimlen(in_ncid, nc_inq_dimid(in_ncid, "latitude", &dimids[1]), &dimlen[1]);
    ret |= nc_inq_dimlen(in_ncid, nc_inq_dimid(in_ncid, "longitude", &dimids[2]), &dimlen[2]);
    if (ret != NC_NOERR) {
        fprintf(stderr, "Error getting dimension lengths.\n");
        nc_close(in_ncid);
        return 1;
    }

    // Close the NetCDF3 file
    nc_close(in_ncid);

    // Create a new NetCDF4 file
    ret = nc_create(OUT_FILE, NC_NETCDF4, &out_ncid);
    if (ret != NC_NOERR) {
        fprintf(stderr, "Error creating NetCDF4 file.\n");
        fprintf(stderr, "ERROR MSG: %s\n", nc_strerror(ret));
        return 1;
    }

    // Define dimensions in the NetCDF4 file
    ret = nc_def_dim(out_ncid, "time", dimlen[0], &dimids[0]);
    ret |= nc_def_dim(out_ncid, "latitude", dimlen[1], &dimids[1]);
    ret |= nc_def_dim(out_ncid, "longitude", dimlen[2], &dimids[2]);
    if (ret != NC_NOERR) {
        fprintf(stderr, "Error defining dimensions in NetCDF4 file.\n");
        nc_close(out_ncid);
        return 1;
    }

    // Loop over variables
    for (int i = 0; i < VAR_LEN; ++i) {
        // Allocate memory to store the data for each variable
        data[i] = malloc(dimlen[0] * dimlen[1] * dimlen[2] * sizeof(float));

        // Read the data from the NetCDF3 file
        ret = nc_open(IN_FILE, NC_NOWRITE, &in_ncid);
        ret |= nc_inq_varid(in_ncid, varname[i], &in_varids[i]);
        ret |= nc_get_var(in_ncid, in_varids[i], data[i]);
        if (ret != NC_NOERR) {
            fprintf(stderr, "Error reading data from NetCDF3 file for %s.\n", varname[i]);
            free(data[i]);
            nc_close(in_ncid);
            nc_close(out_ncid);
            return 1;
        }

        // Write the data to the NetCDF4 file
        ret = nc_put_var(out_ncid, out_varids[i], data[i]);
        if (ret != NC_NOERR) {
            fprintf(stderr, "Error writing data to NetCDF4 file for %s.\n", varname[i]);
            free(data[i]);
            nc_close(out_ncid);
            return 1;
        }

        // Close the NetCDF3 file
        nc_close(in_ncid);
    }

    // Close the NetCDF4 file
    nc_close(out_ncid);

    // Free allocated memory
    for (int i = 0; i < VAR_LEN; ++i) {
        free(data[i]);
    }

    printf("NetCDF3 to NetCDF4 conversion successful.\n");

    return 0;
}
