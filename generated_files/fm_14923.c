#include "fm_14923.h"

inline int fm_14923(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_16_7.data[i][j] - 16*bmats.A_16_8.data[i][j] - bmats.A_24_15.data[i][j] + bmats.Ax1469.data[i][j] + bmats.Ax3489.data[i][j] + bmats.Ax7798.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_16.data[i][j] - bmats.B_12_16.data[i][j] - bmats.B_1_16.data[i][j] + bmats.B_32_8.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_9_16.data[i][j] - bmats.Bx10449.data[i][j] - bmats.Bx13230.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}