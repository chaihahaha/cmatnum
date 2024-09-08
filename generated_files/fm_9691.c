#include "fm_9691.h"

inline int fm_9691(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.Ax791.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.Bx13223.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_15.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
