#include "fm_541.h"

inline int fm_541(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_28_29.data[i][j] - 16*bmats.A_28_30.data[i][j] + bmats.Ax1088.data[i][j] + bmats.Ax1868.data[i][j] + bmats.Ax2277.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_30.data[i][j] - bmats.B_28_28.data[i][j] - bmats.B_29_28.data[i][j] - bmats.B_30_1.data[i][j] - bmats.B_30_28.data[i][j] - bmats.Bx2491.data[i][j] - bmats.Bx4625.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}