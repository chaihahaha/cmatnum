#include "fm_1244.h"

inline int fm_1244(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_5_7.data[i][j] + bmats.A_5_8.data[i][j] - 17*bmats.A_6_7.data[i][j] + 17*bmats.A_7_6.data[i][j] + bmats.Ax3467.data[i][j] + bmats.Ax3817.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_7.data[i][j] - bmats.B_11_7.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_13_7.data[i][j] - bmats.B_14_7.data[i][j] - bmats.B_15_7.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_1_7.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_3_7.data[i][j] - bmats.B_4_7.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_6_1.data[i][j] - bmats.B_6_10.data[i][j] - bmats.B_6_11.data[i][j] - bmats.B_6_12.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_6_15.data[i][j] - bmats.B_6_16.data[i][j] - bmats.B_6_2.data[i][j] - bmats.B_6_3.data[i][j] - bmats.B_6_4.data[i][j] - bmats.B_6_5.data[i][j] - bmats.B_6_6.data[i][j] - 2*bmats.B_6_7.data[i][j] - bmats.B_6_8.data[i][j] - bmats.B_6_9.data[i][j] + bmats.B_7_6.data[i][j] - bmats.B_7_7.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_9_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}