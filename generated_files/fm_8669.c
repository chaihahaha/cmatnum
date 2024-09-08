#include "fm_8669.h"

inline int fm_8669(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_19.data[i][j] + 16*bmats.A_10_20.data[i][j] + 16*bmats.A_20_7.data[i][j] - bmats.A_20_8.data[i][j] + bmats.A_23_23.data[i][j] + bmats.A_23_25.data[i][j] - 16*bmats.A_23_26.data[i][j] - bmats.Ax3125.data[i][j] - bmats.Ax3405.data[i][j] - bmats.Ax7040.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_23.data[i][j] + bmats.B_26_4.data[i][j] + bmats.B_7_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
