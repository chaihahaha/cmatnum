#include "fm_8159.h"

inline int fm_8159(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_10.data[i][j] + 16*bmats.A_18_9.data[i][j] + bmats.A_25_20.data[i][j] - 16*bmats.A_25_21.data[i][j] + bmats.A_25_25.data[i][j] + bmats.A_25_31.data[i][j] + bmats.A_25_32.data[i][j] - bmats.A_5_17.data[i][j] + 16*bmats.A_5_18.data[i][j] - bmats.Ax2834.data[i][j] - bmats.Ax4395.data[i][j] - bmats.Ax6862.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_25.data[i][j] + bmats.B_21_2.data[i][j] + bmats.B_9_21.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_25.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
