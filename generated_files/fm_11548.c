#include "fm_11548.h"

inline int fm_11548(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_6_21.data[i][j] - bmats.A_6_22.data[i][j] - bmats.Ax3853.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_6_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_22.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}