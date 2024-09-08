#include "fm_1100.h"

inline int fm_1100(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_24_23.data[i][j] - 16*bmats.A_24_24.data[i][j] - bmats.A_8_31.data[i][j] + bmats.Ax115.data[i][j] + bmats.Ax1449.data[i][j] + bmats.Ax3419.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_24.data[i][j] - bmats.B_18_24.data[i][j] - bmats.B_19_24.data[i][j] - bmats.B_20_24.data[i][j] - bmats.B_21_24.data[i][j] - bmats.B_22_24.data[i][j] - bmats.B_23_24.data[i][j] - bmats.B_24_1.data[i][j] - bmats.B_24_2.data[i][j] - bmats.B_24_24.data[i][j] - bmats.B_24_3.data[i][j] - bmats.B_24_4.data[i][j] - bmats.B_24_5.data[i][j] - bmats.B_25_24.data[i][j] - bmats.B_26_24.data[i][j] - bmats.B_27_24.data[i][j] - bmats.B_28_24.data[i][j] - bmats.B_29_24.data[i][j] - bmats.B_30_24.data[i][j] - bmats.B_31_24.data[i][j] - bmats.B_32_24.data[i][j] + bmats.B_8_24.data[i][j] - bmats.Bx9722.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
