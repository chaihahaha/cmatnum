#include "fm_14652.h"

inline int fm_14652(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_21.data[i][j] - bmats.A_14_22.data[i][j] + 16*bmats.A_21_10.data[i][j] - bmats.A_21_9.data[i][j] + bmats.A_26_28.data[i][j] - 16*bmats.A_26_30.data[i][j] - bmats.Ax1630.data[i][j] - bmats.Ax2816.data[i][j] - bmats.Ax3055.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_30.data[i][j] + bmats.B_21_26.data[i][j] + bmats.B_30_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}