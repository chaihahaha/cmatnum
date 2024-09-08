#include "fm_9833.h"

inline int fm_9833(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_8_31.data[i][j] + 16*bmats.A_8_32.data[i][j] - bmats.Ax766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_8_16.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_24.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
