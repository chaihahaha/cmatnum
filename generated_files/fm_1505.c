#include "fm_1505.h"

inline int fm_1505(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_16.data[i][j] - 16*bmats.A_5_3.data[i][j] + bmats.A_5_4.data[i][j] + bmats.Ax4126.data[i][j] + bmats.Ax4242.data[i][j] + bmats.Ax962.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_5.data[i][j] - bmats.B_11_5.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_5.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_1_5.data[i][j] + bmats.B_21_3.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_3_18.data[i][j] - bmats.B_3_19.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_3_25.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_3_27.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_3_30.data[i][j] - bmats.B_3_31.data[i][j] - bmats.B_3_32.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_4_5.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_6_5.data[i][j] - bmats.B_7_5.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_9_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}