#include "fm_534.h"

inline int fm_534(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_12_13.data[i][j] + bmats.A_12_14.data[i][j] - bmats.A_29_14.data[i][j] + bmats.Ax1024.data[i][j] + bmats.Ax2320.data[i][j] + bmats.Ax983.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_11_12.data[i][j] - bmats.B_12_12.data[i][j] - bmats.B_13_12.data[i][j] - bmats.B_14_12.data[i][j] - bmats.B_1_12.data[i][j] + bmats.B_28_13.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_5_12.data[i][j] - bmats.Bx4620.data[i][j] - bmats.Bx4641.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}