#include "fm_4007.h"

inline int fm_4007(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_25_7.data[i][j] + 16*bmats.A_25_8.data[i][j] + bmats.A_5_10.data[i][j] - 16*bmats.A_5_9.data[i][j] + 16*bmats.A_8_21.data[i][j] - bmats.A_8_22.data[i][j] - bmats.Ax3322.data[i][j] - bmats.Ax3538.data[i][j] - bmats.Ax5350.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_9.data[i][j] + bmats.B_8_5.data[i][j] + bmats.B_9_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_24.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}