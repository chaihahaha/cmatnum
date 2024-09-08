#include "fm_12770.h"

inline int fm_12770(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_22_13.data[i][j] - bmats.A_22_14.data[i][j] + bmats.A_29_17.data[i][j] + bmats.A_29_18.data[i][j] + bmats.A_29_19.data[i][j] + bmats.A_29_20.data[i][j] - 16*bmats.A_29_25.data[i][j] + bmats.A_29_29.data[i][j] - bmats.A_9_21.data[i][j] + 16*bmats.A_9_22.data[i][j] - bmats.Ax3296.data[i][j] - bmats.Ax524.data[i][j] - bmats.Ax7532.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_25.data[i][j] + bmats.B_22_29.data[i][j] + bmats.B_25_6.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
