#include "fm_1332.h"

inline int fm_1332(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_24_15.data[i][j] + bmats.A_6_7.data[i][j] - 16*bmats.A_6_8.data[i][j] + bmats.Ax1469.data[i][j] + bmats.Ax3470.data[i][j] + bmats.Ax3867.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_6.data[i][j] - bmats.B_15_6.data[i][j] - bmats.B_16_6.data[i][j] - bmats.B_1_6.data[i][j] + bmats.B_22_8.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_3_6.data[i][j] - bmats.B_4_6.data[i][j] - bmats.B_5_6.data[i][j] - bmats.Bx10449.data[i][j] - bmats.Bx10888.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}