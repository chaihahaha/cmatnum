#include "fm_7404.h"

inline int fm_7404(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_29.data[i][j] + 16*bmats.A_13_30.data[i][j] + bmats.A_17_17.data[i][j] + bmats.A_17_19.data[i][j] + bmats.A_17_20.data[i][j] - 16*bmats.A_17_29.data[i][j] + bmats.A_17_30.data[i][j] + bmats.A_17_31.data[i][j] + bmats.A_17_32.data[i][j] + 16*bmats.A_30_1.data[i][j] - bmats.A_30_2.data[i][j] - bmats.Ax1763.data[i][j] - bmats.Ax408.data[i][j] - bmats.Ax6610.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_29.data[i][j] + bmats.B_29_14.data[i][j] + bmats.B_30_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
