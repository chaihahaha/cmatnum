#include "fm_1230.h"

inline int fm_1230(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_23_3.data[i][j] + 16*bmats.A_23_4.data[i][j] + 16*bmats.A_3_7.data[i][j] - bmats.A_3_8.data[i][j] - bmats.A_4_31.data[i][j] - bmats.A_4_32.data[i][j] + 16*bmats.A_7_7.data[i][j] - bmats.A_7_8.data[i][j] - bmats.Ax3458.data[i][j] - bmats.Ax3461.data[i][j] - bmats.Ax3660.data[i][j] - bmats.Ax3807.data[i][j] - bmats.Ax778.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_7.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_22_7.data[i][j] - bmats.B_23_7.data[i][j] - bmats.B_31_7.data[i][j] - bmats.B_32_7.data[i][j] - bmats.B_4_1.data[i][j] - bmats.B_4_10.data[i][j] - bmats.B_4_11.data[i][j] - bmats.B_4_12.data[i][j] - bmats.B_4_13.data[i][j] - bmats.B_4_14.data[i][j] - bmats.B_4_15.data[i][j] - bmats.B_4_16.data[i][j] - bmats.B_4_2.data[i][j] - bmats.B_4_3.data[i][j] - bmats.B_4_4.data[i][j] - bmats.B_4_5.data[i][j] - bmats.B_4_6.data[i][j] - bmats.B_4_7.data[i][j] - bmats.B_4_8.data[i][j] - bmats.B_4_9.data[i][j] + bmats.B_7_20.data[i][j] - bmats.Bx10008.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}