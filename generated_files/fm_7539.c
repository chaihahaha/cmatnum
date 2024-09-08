#include "fm_7539.h"

inline int fm_7539(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_17_17.data[i][j] + bmats.A_17_19.data[i][j] - 16*bmats.A_17_21.data[i][j] + bmats.A_17_22.data[i][j] + bmats.A_17_29.data[i][j] + bmats.A_17_30.data[i][j] + bmats.A_17_31.data[i][j] + bmats.A_17_32.data[i][j] + 16*bmats.A_25_1.data[i][j] - bmats.A_25_2.data[i][j] + 16*bmats.A_5_25.data[i][j] - bmats.A_5_26.data[i][j] - bmats.Ax2854.data[i][j] - bmats.Ax3507.data[i][j] - bmats.Ax6612.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_21.data[i][j] + bmats.B_21_9.data[i][j] + bmats.B_25_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
