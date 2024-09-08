#include "fm_1099.h"

inline int fm_1099(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_23.data[i][j] + 16*bmats.A_18_24.data[i][j] - bmats.A_24_15.data[i][j] - bmats.A_24_16.data[i][j] - bmats.A_24_23.data[i][j] + 16*bmats.A_24_24.data[i][j] - bmats.A_8_23.data[i][j] + 16*bmats.A_8_24.data[i][j] - bmats.Ax115.data[i][j] - bmats.Ax3386.data[i][j] - bmats.Ax340.data[i][j] - bmats.Ax3430.data[i][j] - bmats.Ax697.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_24.data[i][j] - bmats.B_11_24.data[i][j] - bmats.B_12_24.data[i][j] - bmats.B_13_24.data[i][j] - bmats.B_14_24.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_16_24.data[i][j] - bmats.B_1_24.data[i][j] - bmats.B_24_17.data[i][j] - bmats.B_24_18.data[i][j] - bmats.B_24_19.data[i][j] - bmats.B_24_20.data[i][j] - bmats.B_24_21.data[i][j] - bmats.B_24_22.data[i][j] - bmats.B_24_23.data[i][j] - bmats.B_24_24.data[i][j] - bmats.B_24_25.data[i][j] - bmats.B_24_26.data[i][j] - bmats.B_24_27.data[i][j] - bmats.B_24_28.data[i][j] - bmats.B_24_29.data[i][j] - bmats.B_24_30.data[i][j] - bmats.B_24_31.data[i][j] - bmats.B_24_32.data[i][j] + bmats.B_24_8.data[i][j] - bmats.B_2_24.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_4_24.data[i][j] - bmats.B_5_24.data[i][j] - bmats.B_6_24.data[i][j] - bmats.B_7_24.data[i][j] - bmats.B_8_24.data[i][j] - bmats.B_9_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
