#include "fm_11106.h"

inline int fm_11106(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_16_23.data[i][j] - bmats.A_16_24.data[i][j] - bmats.Ax3424.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_32.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}