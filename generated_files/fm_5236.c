#include "fm_5236.h"

inline int fm_5236(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_20_7.data[i][j] - bmats.A_20_8.data[i][j] + 16*bmats.A_7_25.data[i][j] - bmats.A_7_26.data[i][j] + bmats.A_9_3.data[i][j] - 16*bmats.A_9_4.data[i][j] - bmats.Ax2860.data[i][j] - bmats.Ax3405.data[i][j] - bmats.Ax5726.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_25_4.data[i][j] + bmats.B_4_23.data[i][j] + bmats.B_7_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}