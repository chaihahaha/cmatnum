#include "fm_1710.h"

inline int fm_1710(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_28_15.data[i][j] + bmats.A_3_11.data[i][j] - 16*bmats.A_3_12.data[i][j] + bmats.Ax1329.data[i][j] + bmats.Ax2208.data[i][j] + bmats.Ax4519.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_11_3.data[i][j] - bmats.B_12_3.data[i][j] - bmats.B_14_3.data[i][j] + bmats.B_19_12.data[i][j] - bmats.B_1_3.data[i][j] - bmats.B_5_3.data[i][j] - bmats.B_7_3.data[i][j] - bmats.B_9_3.data[i][j] - bmats.Bx12416.data[i][j] - bmats.Bx6296.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
