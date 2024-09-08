#include "fm_9038.h"

inline int fm_9038(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_25.data[i][j] + 16*bmats.A_1_26.data[i][j] - 16*bmats.A_25_17.data[i][j] + bmats.A_25_32.data[i][j] - bmats.A_26_10.data[i][j] + 16*bmats.A_26_9.data[i][j] - bmats.Ax2813.data[i][j] - bmats.Ax2869.data[i][j] - bmats.Ax3290.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_10.data[i][j] + bmats.B_26_25.data[i][j] + bmats.B_9_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_25.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
