#include "fm_1329.h"

inline int fm_1329(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_5.data[i][j] + 16*bmats.A_1_6.data[i][j] - bmats.A_22_7.data[i][j] + 16*bmats.A_22_8.data[i][j] - bmats.A_6_5.data[i][j] + 16*bmats.A_6_6.data[i][j] - bmats.A_8_31.data[i][j] - bmats.A_8_32.data[i][j] - bmats.Ax3411.data[i][j] - bmats.Ax3917.data[i][j] - bmats.Ax3953.data[i][j] - bmats.Ax3955.data[i][j] - bmats.Ax766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_32_6.data[i][j] + bmats.B_6_24.data[i][j] - bmats.B_8_1.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_8_3.data[i][j] - bmats.B_8_4.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_8_6.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_8_8.data[i][j] - bmats.B_8_9.data[i][j] - bmats.Bx10674.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
