#include "fm_1188.h"

inline int fm_1188(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_23_27.data[i][j] - 16*bmats.A_26_23.data[i][j] + bmats.A_26_24.data[i][j] - 17*bmats.A_27_23.data[i][j] + bmats.Ax3754.data[i][j] + bmats.Ax50.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_23.data[i][j] - bmats.B_18_23.data[i][j] - bmats.B_19_23.data[i][j] - bmats.B_20_23.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_22_23.data[i][j] - bmats.B_23_23.data[i][j] + bmats.B_23_27.data[i][j] - bmats.B_24_23.data[i][j] - bmats.B_25_23.data[i][j] - bmats.B_26_23.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_27_18.data[i][j] - 2*bmats.B_27_23.data[i][j] - bmats.B_28_23.data[i][j] - bmats.B_29_23.data[i][j] - bmats.B_30_23.data[i][j] - bmats.B_31_23.data[i][j] - bmats.B_32_23.data[i][j] - bmats.Bx7425.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}