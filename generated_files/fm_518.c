#include "fm_518.h"

inline int fm_518(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_13_17.data[i][j] + bmats.A_13_18.data[i][j] + bmats.A_13_19.data[i][j] + bmats.A_13_20.data[i][j] + bmats.A_13_21.data[i][j] + bmats.A_13_22.data[i][j] + bmats.A_13_23.data[i][j] + bmats.A_13_24.data[i][j] + bmats.A_13_25.data[i][j] + bmats.A_13_26.data[i][j] + bmats.A_13_27.data[i][j] + bmats.A_13_28.data[i][j] + bmats.A_13_29.data[i][j] + bmats.A_13_30.data[i][j] + bmats.A_13_31.data[i][j] + bmats.A_13_32.data[i][j] - bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - bmats.Ax1867.data[i][j] - bmats.Ax652.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_29.data[i][j] - bmats.B_11_29.data[i][j] - bmats.B_12_29.data[i][j] + bmats.B_13_1.data[i][j] - bmats.B_13_29.data[i][j] - bmats.B_14_29.data[i][j] - bmats.B_15_29.data[i][j] - bmats.B_16_29.data[i][j] - bmats.B_17_1.data[i][j] - bmats.B_17_10.data[i][j] - bmats.B_17_11.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_17_16.data[i][j] - bmats.B_17_2.data[i][j] - bmats.B_17_3.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_17_7.data[i][j] - bmats.B_17_8.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_1_29.data[i][j] - bmats.B_2_29.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_4_29.data[i][j] - bmats.B_5_29.data[i][j] - bmats.B_6_29.data[i][j] - bmats.B_7_29.data[i][j] - bmats.B_8_29.data[i][j] - bmats.B_9_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
