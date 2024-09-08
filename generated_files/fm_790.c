#include "fm_790.h"

inline int fm_790(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_15.data[i][j] - bmats.A_10_16.data[i][j] - 16*bmats.A_10_26.data[i][j] + bmats.A_10_31.data[i][j] - bmats.Ax2970.data[i][j] - bmats.Ax582.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_10.data[i][j] - bmats.B_10_26.data[i][j] - bmats.B_11_26.data[i][j] - bmats.B_12_26.data[i][j] - bmats.B_13_26.data[i][j] - bmats.B_14_26.data[i][j] - bmats.B_15_26.data[i][j] - bmats.B_16_26.data[i][j] - bmats.B_1_26.data[i][j] - bmats.B_26_1.data[i][j] - bmats.B_26_10.data[i][j] - bmats.B_26_11.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_26_13.data[i][j] - bmats.B_26_14.data[i][j] - bmats.B_26_15.data[i][j] - bmats.B_26_16.data[i][j] - bmats.B_26_2.data[i][j] - bmats.B_26_3.data[i][j] - bmats.B_26_4.data[i][j] - bmats.B_26_5.data[i][j] - bmats.B_26_6.data[i][j] - bmats.B_26_7.data[i][j] - bmats.B_26_8.data[i][j] - bmats.B_26_9.data[i][j] - bmats.B_2_26.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_4_26.data[i][j] - bmats.B_5_26.data[i][j] - bmats.B_6_26.data[i][j] - bmats.B_7_26.data[i][j] - bmats.B_8_26.data[i][j] - bmats.B_9_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
