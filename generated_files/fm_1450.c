#include "fm_1450.h"

inline int fm_1450(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_14_5.data[i][j] + bmats.A_14_6.data[i][j] + 17*bmats.A_5_9.data[i][j] - 17*bmats.A_9_5.data[i][j] + bmats.Ax1656.data[i][j] + bmats.Ax4212.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_5.data[i][j] - bmats.B_11_5.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_5.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_1_5.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_4_5.data[i][j] - bmats.B_5_5.data[i][j] + bmats.B_5_9.data[i][j] - bmats.B_6_5.data[i][j] - bmats.B_7_5.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_9_1.data[i][j] - bmats.B_9_10.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_12.data[i][j] - bmats.B_9_13.data[i][j] - bmats.B_9_14.data[i][j] - bmats.B_9_15.data[i][j] - bmats.B_9_16.data[i][j] - bmats.B_9_2.data[i][j] - bmats.B_9_3.data[i][j] - bmats.B_9_4.data[i][j] - 2*bmats.B_9_5.data[i][j] - bmats.B_9_6.data[i][j] - bmats.B_9_7.data[i][j] - bmats.B_9_8.data[i][j] - bmats.B_9_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
