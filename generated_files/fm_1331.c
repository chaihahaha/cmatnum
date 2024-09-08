#include "fm_1331.h"

inline int fm_1331(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_22_23.data[i][j] - 16*bmats.A_22_24.data[i][j] - bmats.A_8_31.data[i][j] + bmats.Ax1449.data[i][j] + bmats.Ax354.data[i][j] + bmats.Ax3987.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_22.data[i][j] - bmats.B_18_22.data[i][j] - bmats.B_19_22.data[i][j] - bmats.B_20_22.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_23_22.data[i][j] - bmats.B_24_1.data[i][j] - bmats.B_24_2.data[i][j] - bmats.B_24_3.data[i][j] - bmats.B_24_4.data[i][j] - bmats.B_24_5.data[i][j] - bmats.B_30_22.data[i][j] - bmats.B_31_22.data[i][j] - bmats.B_32_22.data[i][j] + bmats.B_6_24.data[i][j] - bmats.Bx10896.data[i][j] - bmats.Bx9722.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
