#include "fm_8911.h"

inline int fm_8911(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -2*bmats.A_7_8.data[i][j] + 15*bmats.A_7_9.data[i][j] + 16*bmats.A_9_7.data[i][j] - bmats.A_9_8.data[i][j] - bmats.Ax3252.data[i][j] - bmats.Ax7380.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_7_7.data[i][j] + bmats.B_7_9.data[i][j] + bmats.B_9_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}