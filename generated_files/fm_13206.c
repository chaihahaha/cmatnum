#include "fm_13206.h"

inline int fm_13206(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_17.data[i][j] - bmats.A_10_18.data[i][j] - bmats.Ax3111.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_1.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_26.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
