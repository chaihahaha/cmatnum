#include "fm_1275.h"

inline int fm_1275(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_3_15.data[i][j] - bmats.A_3_16.data[i][j] + bmats.A_7_17.data[i][j] + bmats.A_7_18.data[i][j] - 16*bmats.A_7_19.data[i][j] + bmats.A_7_20.data[i][j] + bmats.A_7_21.data[i][j] + bmats.A_7_22.data[i][j] + bmats.A_7_23.data[i][j] + bmats.A_7_24.data[i][j] + bmats.A_7_25.data[i][j] + bmats.A_7_26.data[i][j] + bmats.A_7_27.data[i][j] + bmats.A_7_28.data[i][j] + bmats.A_7_29.data[i][j] + bmats.A_7_30.data[i][j] + bmats.A_7_31.data[i][j] + bmats.A_7_32.data[i][j] - bmats.Ax3692.data[i][j] - bmats.Ax585.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_12_23.data[i][j] - bmats.B_13_23.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_16_23.data[i][j] - bmats.B_19_1.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_19_16.data[i][j] - bmats.B_19_2.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_1_23.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_4_23.data[i][j] - bmats.B_5_23.data[i][j] - bmats.B_6_23.data[i][j] + bmats.B_7_3.data[i][j] - bmats.Bx10243.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}