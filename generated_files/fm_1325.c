#include "fm_1325.h"

inline int fm_1325(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_6_23.data[i][j] + bmats.A_6_29.data[i][j] - bmats.A_7_15.data[i][j] - bmats.A_7_16.data[i][j] - bmats.Ax4011.data[i][j] - bmats.Ax573.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_11_22.data[i][j] - bmats.B_14_22.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_16_22.data[i][j] - bmats.B_1_22.data[i][j] - bmats.B_23_10.data[i][j] - bmats.B_23_11.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_23_13.data[i][j] - bmats.B_23_14.data[i][j] - bmats.B_23_15.data[i][j] - bmats.B_23_16.data[i][j] - bmats.B_23_7.data[i][j] - bmats.B_23_8.data[i][j] - bmats.B_23_9.data[i][j] - bmats.B_2_22.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_4_22.data[i][j] - bmats.B_5_22.data[i][j] - bmats.B_6_22.data[i][j] + bmats.B_6_7.data[i][j] - bmats.Bx10907.data[i][j] - bmats.Bx11066.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
