#include "fm_1776.h"

inline int fm_1776(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_14.data[i][j] + bmats.A_3_1.data[i][j] - 16*bmats.A_3_2.data[i][j] + bmats.Ax4519.data[i][j] + bmats.Ax4592.data[i][j] + bmats.Ax898.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_3.data[i][j] - bmats.B_15_3.data[i][j] - bmats.B_16_3.data[i][j] + bmats.B_19_2.data[i][j] - bmats.B_1_3.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_2_18.data[i][j] - bmats.B_2_19.data[i][j] - bmats.B_2_20.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_2_22.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_2_24.data[i][j] - bmats.B_2_25.data[i][j] - bmats.B_2_26.data[i][j] - bmats.B_2_27.data[i][j] - bmats.B_2_28.data[i][j] - bmats.B_2_29.data[i][j] - bmats.B_2_3.data[i][j] - bmats.B_2_30.data[i][j] - bmats.B_2_31.data[i][j] - bmats.B_2_32.data[i][j] - bmats.B_6_3.data[i][j] - bmats.Bx12291.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}