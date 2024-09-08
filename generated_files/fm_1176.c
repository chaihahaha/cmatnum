#include "fm_1176.h"

inline int fm_1176(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_15.data[i][j] - bmats.A_15_16.data[i][j] + bmats.A_7_26.data[i][j] - 16*bmats.A_7_31.data[i][j] - bmats.Ax3749.data[i][j] - bmats.Ax649.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_23.data[i][j] - bmats.B_11_23.data[i][j] - bmats.B_12_23.data[i][j] - bmats.B_13_23.data[i][j] - bmats.B_14_23.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_16_23.data[i][j] - bmats.B_1_23.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_31_1.data[i][j] - bmats.B_31_10.data[i][j] - bmats.B_31_11.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_31_14.data[i][j] - bmats.B_31_15.data[i][j] - bmats.B_31_16.data[i][j] - bmats.B_31_2.data[i][j] - bmats.B_31_3.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_31_5.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_31_7.data[i][j] - bmats.B_31_8.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_4_23.data[i][j] - bmats.B_5_23.data[i][j] - bmats.B_6_23.data[i][j] + bmats.B_7_15.data[i][j] - bmats.B_7_23.data[i][j] - bmats.B_8_23.data[i][j] - bmats.B_9_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
