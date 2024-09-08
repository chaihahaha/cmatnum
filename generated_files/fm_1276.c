#include "fm_1276.h"

inline int fm_1276(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_31.data[i][j] - bmats.A_19_32.data[i][j] + bmats.A_23_1.data[i][j] + bmats.A_23_10.data[i][j] + bmats.A_23_11.data[i][j] + bmats.A_23_12.data[i][j] + bmats.A_23_13.data[i][j] + bmats.A_23_14.data[i][j] + bmats.A_23_15.data[i][j] + bmats.A_23_16.data[i][j] + bmats.A_23_2.data[i][j] - 16*bmats.A_23_3.data[i][j] + bmats.A_23_4.data[i][j] + bmats.A_23_5.data[i][j] + bmats.A_23_6.data[i][j] + bmats.A_23_7.data[i][j] + bmats.A_23_8.data[i][j] + bmats.A_23_9.data[i][j] - bmats.Ax3713.data[i][j] - bmats.Ax630.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_7.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_22_7.data[i][j] + bmats.B_23_19.data[i][j] - bmats.B_23_7.data[i][j] - bmats.B_31_7.data[i][j] - bmats.B_32_7.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_3_18.data[i][j] - bmats.B_3_19.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_3_25.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_3_27.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_3_30.data[i][j] - bmats.B_3_31.data[i][j] - bmats.B_3_32.data[i][j] - bmats.Bx10008.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
