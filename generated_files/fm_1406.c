#include "fm_1406.h"

inline int fm_1406(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_31_3.data[i][j] - 16*bmats.A_5_15.data[i][j] + bmats.A_5_16.data[i][j] + bmats.Ax1152.data[i][j] + bmats.Ax4126.data[i][j] + bmats.Ax591.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_5.data[i][j] - bmats.B_11_5.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_17.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_15_20.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_15_25.data[i][j] - bmats.B_15_26.data[i][j] - bmats.B_15_27.data[i][j] - bmats.B_15_28.data[i][j] - bmats.B_15_29.data[i][j] - bmats.B_15_30.data[i][j] - bmats.B_15_31.data[i][j] - bmats.B_15_32.data[i][j] - bmats.B_15_5.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_1_5.data[i][j] + bmats.B_21_15.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_4_5.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_6_5.data[i][j] - bmats.B_7_5.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_9_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}