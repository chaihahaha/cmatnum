#include "fm_10134.h"

inline int fm_10134(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_2_29.data[i][j] + 16*bmats.A_2_30.data[i][j] - bmats.Ax429.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_2_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_18.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}