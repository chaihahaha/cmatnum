#include "fm_1265.h"

inline int fm_1265(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_23_17.data[i][j] - 16*bmats.A_23_18.data[i][j] - bmats.A_2_30.data[i][j] + bmats.Ax3692.data[i][j] + bmats.Ax85.data[i][j] + bmats.Ax878.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_23.data[i][j] - bmats.B_18_1.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_18_11.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_18_15.data[i][j] - bmats.B_18_16.data[i][j] - bmats.B_18_2.data[i][j] - bmats.B_18_23.data[i][j] - bmats.B_18_3.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_23.data[i][j] - bmats.B_20_23.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_22_23.data[i][j] - bmats.B_26_23.data[i][j] - bmats.B_30_23.data[i][j] - bmats.B_31_23.data[i][j] - bmats.B_32_23.data[i][j] + bmats.B_7_18.data[i][j] - bmats.Bx9994.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}