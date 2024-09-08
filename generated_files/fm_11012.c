#include "fm_11012.h"

inline int fm_11012(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_23.data[i][j] + 16*bmats.A_12_24.data[i][j] - bmats.Ax2457.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_8.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_28.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
