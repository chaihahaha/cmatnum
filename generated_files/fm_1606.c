#include "fm_1606.h"

inline int fm_1606(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_4_8.data[i][j] - 17*bmats.A_8_4.data[i][j] + bmats.A_9_3.data[i][j] - 16*bmats.A_9_4.data[i][j] + bmats.Ax3357.data[i][j] + bmats.Ax4423.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_4.data[i][j] - bmats.B_11_4.data[i][j] - bmats.B_12_4.data[i][j] - bmats.B_13_4.data[i][j] - bmats.B_14_4.data[i][j] - bmats.B_15_4.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_1_4.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_3_4.data[i][j] - bmats.B_4_4.data[i][j] + bmats.B_4_8.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_6_4.data[i][j] - bmats.B_7_4.data[i][j] - bmats.B_8_1.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_8_3.data[i][j] - 2*bmats.B_8_4.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_8_6.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_8_8.data[i][j] - bmats.B_8_9.data[i][j] - bmats.B_9_4.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}