#include "fm_1034.h"

inline int fm_1034(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_23.data[i][j] + 16*bmats.A_18_24.data[i][j] - bmats.A_24_23.data[i][j] + 16*bmats.A_24_24.data[i][j] - bmats.A_28_15.data[i][j] - bmats.A_28_16.data[i][j] - bmats.A_8_27.data[i][j] + 16*bmats.A_8_28.data[i][j] - bmats.Ax115.data[i][j] - bmats.Ax2306.data[i][j] - bmats.Ax3386.data[i][j] - bmats.Ax340.data[i][j] - bmats.Ax688.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_24.data[i][j] - bmats.B_11_24.data[i][j] - bmats.B_12_24.data[i][j] - bmats.B_13_24.data[i][j] - bmats.B_14_24.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_16_24.data[i][j] - bmats.B_1_24.data[i][j] + bmats.B_24_12.data[i][j] - bmats.B_28_18.data[i][j] - bmats.B_28_23.data[i][j] - bmats.B_28_25.data[i][j] - bmats.B_28_26.data[i][j] - bmats.B_28_28.data[i][j] - bmats.B_28_29.data[i][j] - bmats.B_28_30.data[i][j] - bmats.B_28_31.data[i][j] - bmats.B_28_32.data[i][j] - bmats.B_2_24.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_4_24.data[i][j] - bmats.B_5_24.data[i][j] - bmats.B_6_24.data[i][j] - bmats.B_7_24.data[i][j] - bmats.B_8_24.data[i][j] - bmats.B_9_24.data[i][j] - bmats.Bx6292.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
