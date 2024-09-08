#include "fm_773.h"

inline int fm_773(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_13.data[i][j] - 16*bmats.A_10_14.data[i][j] + bmats.Ax1039.data[i][j] + bmats.Ax1900.data[i][j] + bmats.Ax2874.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_10.data[i][j] - bmats.B_11_10.data[i][j] - bmats.B_12_10.data[i][j] - bmats.B_13_10.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_14_17.data[i][j] - bmats.B_15_10.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_1_10.data[i][j] + bmats.B_26_14.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_3_10.data[i][j] - bmats.B_4_10.data[i][j] - bmats.B_5_10.data[i][j] - bmats.B_6_10.data[i][j] - bmats.B_7_10.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_9_10.data[i][j] - bmats.Bx2496.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
