#include "fm_9178.h"

inline int fm_9178(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_2_5.data[i][j] + 16*bmats.A_2_6.data[i][j] + 16*bmats.A_6_7.data[i][j] - bmats.A_6_8.data[i][j] - bmats.A_7_1.data[i][j] + 16*bmats.A_7_2.data[i][j] - bmats.Ax3470.data[i][j] - bmats.Ax3881.data[i][j] - bmats.Ax3920.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_2_6.data[i][j] + bmats.B_6_7.data[i][j] + bmats.B_7_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}