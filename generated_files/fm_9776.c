#include "fm_9776.h"

inline int fm_9776(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_23.data[i][j] + 16*bmats.A_18_24.data[i][j] - bmats.A_24_23.data[i][j] + 16*bmats.A_24_24.data[i][j] - bmats.Ax115.data[i][j] - bmats.Ax3386.data[i][j] - bmats.Ax340.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.Bx13283.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_24.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}