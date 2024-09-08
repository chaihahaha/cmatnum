#include "fm_10890.h"

inline int fm_10890(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_25.data[i][j] - bmats.A_13_26.data[i][j] - bmats.Ax2047.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_29.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
