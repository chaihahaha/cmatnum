#include "fm_13341.h"

inline int fm_13341(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_15.data[i][j] - bmats.A_14_16.data[i][j] + bmats.A_16_28.data[i][j] - 16*bmats.A_16_30.data[i][j] - bmats.Ax392.data[i][j] - bmats.Ax8277.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_32.data[i][j] + bmats.B_16_14.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_30_1.data[i][j] - bmats.Bx13238.data[i][j] - bmats.Bx2491.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}