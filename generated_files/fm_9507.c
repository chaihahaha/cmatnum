#include "fm_9507.h"

inline int fm_9507(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_15.data[i][j] + 16*bmats.A_10_16.data[i][j] + 16*bmats.A_16_3.data[i][j] - bmats.A_16_4.data[i][j] + 16*bmats.A_3_10.data[i][j] - bmats.A_3_9.data[i][j] - bmats.Ax2932.data[i][j] - bmats.Ax4366.data[i][j] - bmats.Ax582.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_16.data[i][j] + bmats.B_16_3.data[i][j] + bmats.B_3_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}