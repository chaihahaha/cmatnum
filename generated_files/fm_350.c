#include "fm_350.h"

inline int fm_350(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_13.data[i][j] + 16*bmats.A_14_14.data[i][j] - bmats.A_1_13.data[i][j] + 16*bmats.A_1_14.data[i][j] + 16*bmats.A_30_7.data[i][j] - bmats.A_30_8.data[i][j] - bmats.A_7_31.data[i][j] - bmats.A_7_32.data[i][j] - bmats.Ax1012.data[i][j] - bmats.Ax1056.data[i][j] - bmats.Ax1422.data[i][j] - bmats.Ax763.data[i][j] - bmats.Ax965.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_23.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_23_14.data[i][j] - bmats.B_24_14.data[i][j] - bmats.B_25_14.data[i][j] - bmats.B_26_14.data[i][j] - bmats.B_27_14.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_29_14.data[i][j] - bmats.B_30_14.data[i][j] - bmats.B_31_14.data[i][j] - bmats.B_32_14.data[i][j] - bmats.B_7_1.data[i][j] - bmats.B_7_10.data[i][j] - bmats.B_7_11.data[i][j] - bmats.B_7_12.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_7_15.data[i][j] - bmats.B_7_16.data[i][j] - bmats.B_7_2.data[i][j] - bmats.B_7_3.data[i][j] - bmats.B_7_4.data[i][j] - bmats.B_7_5.data[i][j] - bmats.B_7_6.data[i][j] - bmats.B_7_7.data[i][j] - bmats.B_7_8.data[i][j] - bmats.B_7_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
