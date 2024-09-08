#include "fm_1197.h"

inline int fm_1197(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_31.data[i][j] - bmats.A_12_32.data[i][j] - bmats.A_23_11.data[i][j] + 16*bmats.A_23_12.data[i][j] + 16*bmats.A_3_7.data[i][j] - bmats.A_3_8.data[i][j] + 16*bmats.A_7_7.data[i][j] - bmats.A_7_8.data[i][j] - bmats.Ax2260.data[i][j] - bmats.Ax3458.data[i][j] - bmats.Ax3461.data[i][j] - bmats.Ax3660.data[i][j] - bmats.Ax757.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_12_12.data[i][j] - bmats.B_12_14.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_12_9.data[i][j] + bmats.B_7_28.data[i][j] - bmats.Bx10240.data[i][j] - bmats.Bx6289.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
