#include "fm_14065.h"

inline int fm_14065(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_29.data[i][j] - bmats.A_13_30.data[i][j] + bmats.A_26_28.data[i][j] - 16*bmats.A_26_29.data[i][j] + bmats.A_26_31.data[i][j] + 16*bmats.A_29_10.data[i][j] - bmats.A_29_9.data[i][j] - bmats.Ax2044.data[i][j] - bmats.Ax408.data[i][j] - bmats.Ax8316.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_29.data[i][j] + bmats.B_29_13.data[i][j] + bmats.B_29_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
