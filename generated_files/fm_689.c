#include "fm_689.h"

inline int fm_689(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_31.data[i][j] + bmats.A_27_27.data[i][j] - 16*bmats.A_27_28.data[i][j] + bmats.Ax1309.data[i][j] + bmats.Ax2230.data[i][j] + bmats.Ax2598.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_28.data[i][j] - bmats.B_27_27.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_28_15.data[i][j] - bmats.B_28_16.data[i][j] - bmats.B_28_27.data[i][j] - bmats.B_29_27.data[i][j] - bmats.B_30_27.data[i][j] - bmats.Bx5962.data[i][j] - bmats.Bx6294.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
