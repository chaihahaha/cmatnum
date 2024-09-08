#include "fm_1538.h"

inline int fm_1538(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - 16*bmats.A_5_17.data[i][j] + bmats.A_5_18.data[i][j] + bmats.A_5_19.data[i][j] + bmats.A_5_20.data[i][j] + bmats.A_5_21.data[i][j] + bmats.A_5_22.data[i][j] + bmats.A_5_23.data[i][j] + bmats.A_5_24.data[i][j] + bmats.A_5_25.data[i][j] + bmats.A_5_26.data[i][j] + bmats.A_5_27.data[i][j] + bmats.A_5_28.data[i][j] + bmats.A_5_29.data[i][j] + bmats.A_5_30.data[i][j] + bmats.A_5_31.data[i][j] + bmats.A_5_32.data[i][j] - bmats.Ax4141.data[i][j] - bmats.Ax652.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_21.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_17_1.data[i][j] - bmats.B_17_10.data[i][j] - bmats.B_17_11.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_17_16.data[i][j] - bmats.B_17_2.data[i][j] - bmats.B_17_3.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_17_7.data[i][j] - bmats.B_17_8.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_4_21.data[i][j] + bmats.B_5_1.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx11440.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
