#include "fm_8022.h"

inline int fm_8022(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_21_29.data[i][j] - bmats.A_21_30.data[i][j] + 16*bmats.A_24_21.data[i][j] - bmats.A_24_22.data[i][j] - bmats.A_29_23.data[i][j] + 16*bmats.A_29_24.data[i][j] - bmats.Ax110.data[i][j] - bmats.Ax1115.data[i][j] - bmats.Ax2031.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_29.data[i][j] + bmats.B_24_21.data[i][j] + bmats.B_29_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}