#include "fm_1253.h"

inline int fm_1253(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_1_7.data[i][j] - 16*bmats.A_2_7.data[i][j] + bmats.A_2_8.data[i][j] + 17*bmats.A_7_1.data[i][j] + bmats.Ax3476.data[i][j] + bmats.Ax3870.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_7.data[i][j] - bmats.B_11_7.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_13_7.data[i][j] - bmats.B_14_7.data[i][j] - bmats.B_15_7.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_1_1.data[i][j] - bmats.B_1_10.data[i][j] - bmats.B_1_11.data[i][j] - bmats.B_1_12.data[i][j] - bmats.B_1_13.data[i][j] - bmats.B_1_14.data[i][j] - bmats.B_1_15.data[i][j] - bmats.B_1_16.data[i][j] - bmats.B_1_2.data[i][j] - bmats.B_1_3.data[i][j] - bmats.B_1_4.data[i][j] - bmats.B_1_5.data[i][j] - bmats.B_1_6.data[i][j] - 2*bmats.B_1_7.data[i][j] - bmats.B_1_8.data[i][j] - bmats.B_1_9.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_3_7.data[i][j] - bmats.B_4_7.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_6_7.data[i][j] + bmats.B_7_1.data[i][j] - bmats.B_7_7.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_9_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
