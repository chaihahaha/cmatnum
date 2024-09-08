#include "fm_1886.h"

inline int fm_1886(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_1_1.data[i][j] - 16*bmats.A_1_2.data[i][j] - bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] + bmats.Ax4647.data[i][j] + bmats.Ax4661.data[i][j] + bmats.Ax4739.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_2.data[i][j] - bmats.B_11_2.data[i][j] - bmats.B_12_2.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_14_2.data[i][j] - bmats.B_15_2.data[i][j] - bmats.B_16_2.data[i][j] - bmats.B_1_2.data[i][j] - bmats.B_2_1.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_2_16.data[i][j] - bmats.B_2_2.data[i][j] - bmats.B_2_3.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_2_8.data[i][j] - bmats.B_2_9.data[i][j] - bmats.B_3_2.data[i][j] - bmats.B_4_2.data[i][j] - bmats.B_5_2.data[i][j] - bmats.B_6_2.data[i][j] - bmats.B_7_2.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_9_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
