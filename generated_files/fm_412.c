#include "fm_412.h"

inline int fm_412(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_15.data[i][j] - bmats.A_12_16.data[i][j] + bmats.A_13_27.data[i][j] - 16*bmats.A_13_28.data[i][j] - bmats.Ax1971.data[i][j] - bmats.Ax565.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_29.data[i][j] - bmats.B_11_29.data[i][j] - bmats.B_12_29.data[i][j] + bmats.B_13_12.data[i][j] - bmats.B_13_29.data[i][j] - bmats.B_14_29.data[i][j] - bmats.B_15_29.data[i][j] - bmats.B_16_29.data[i][j] - bmats.B_1_29.data[i][j] - bmats.B_28_1.data[i][j] - bmats.B_28_10.data[i][j] - bmats.B_28_11.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_28_15.data[i][j] - bmats.B_28_16.data[i][j] - bmats.B_28_2.data[i][j] - bmats.B_28_3.data[i][j] - bmats.B_28_4.data[i][j] - bmats.B_28_5.data[i][j] - bmats.B_28_6.data[i][j] - bmats.B_28_7.data[i][j] - bmats.B_28_8.data[i][j] - bmats.B_28_9.data[i][j] - bmats.B_2_29.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_4_29.data[i][j] - bmats.B_5_29.data[i][j] - bmats.B_6_29.data[i][j] - bmats.B_7_29.data[i][j] - bmats.B_8_29.data[i][j] - bmats.B_9_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
