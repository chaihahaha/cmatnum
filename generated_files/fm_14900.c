#include "fm_14900.h"

inline int fm_14900(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_16_21.data[i][j] + bmats.A_16_22.data[i][j] - bmats.A_5_15.data[i][j] - bmats.A_5_16.data[i][j] - bmats.Ax591.data[i][j] - bmats.Ax8504.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_32.data[i][j] - bmats.B_16_32.data[i][j] + bmats.B_16_5.data[i][j] - bmats.B_21_1.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_21_11.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_21_15.data[i][j] - bmats.B_21_16.data[i][j] - bmats.B_21_2.data[i][j] - bmats.B_21_3.data[i][j] - bmats.B_21_4.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_21_9.data[i][j] - bmats.Bx13238.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
