#include "fm_9446.h"

inline int fm_9446(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -2*bmats.A_17_18.data[i][j] + 15*bmats.A_17_19.data[i][j] + 16*bmats.A_19_17.data[i][j] - bmats.A_19_18.data[i][j] - bmats.Ax164.data[i][j] - bmats.Ax7684.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_17.data[i][j] + bmats.B_17_19.data[i][j] + bmats.B_19_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
