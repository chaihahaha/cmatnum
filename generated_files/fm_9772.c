#include "fm_9772.h"

inline int fm_9772(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_19_23.data[i][j] - bmats.A_19_24.data[i][j] + 16*bmats.A_23_23.data[i][j] - bmats.A_23_24.data[i][j] - bmats.Ax343.data[i][j] - bmats.Ax357.data[i][j] - bmats.Ax3669.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.Bx13277.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}