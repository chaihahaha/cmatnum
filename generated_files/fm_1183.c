#include "fm_1183.h"

inline int fm_1183(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_32.data[i][j] + bmats.A_23_25.data[i][j] - 16*bmats.A_23_26.data[i][j] + bmats.Ax1566.data[i][j] + bmats.Ax236.data[i][j] + bmats.Ax3692.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_23.data[i][j] - bmats.B_18_23.data[i][j] - bmats.B_19_23.data[i][j] - bmats.B_20_23.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_22_23.data[i][j] - bmats.B_26_23.data[i][j] - bmats.B_30_23.data[i][j] - bmats.B_31_23.data[i][j] - bmats.B_32_23.data[i][j] + bmats.B_7_26.data[i][j] - bmats.Bx7705.data[i][j] - bmats.Bx8679.data[i][j] - bmats.Bx9994.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
