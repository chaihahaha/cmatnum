#include "fm_519.h"

inline int fm_519(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_31.data[i][j] - bmats.A_17_32.data[i][j] - 16*bmats.A_29_1.data[i][j] + bmats.A_29_10.data[i][j] + bmats.A_29_11.data[i][j] + bmats.A_29_12.data[i][j] + bmats.A_29_13.data[i][j] + bmats.A_29_14.data[i][j] + bmats.A_29_15.data[i][j] + bmats.A_29_16.data[i][j] + bmats.A_29_2.data[i][j] + bmats.A_29_3.data[i][j] + bmats.A_29_4.data[i][j] + bmats.A_29_5.data[i][j] + bmats.A_29_6.data[i][j] + bmats.A_29_7.data[i][j] + bmats.A_29_8.data[i][j] + bmats.A_29_9.data[i][j] - bmats.Ax1899.data[i][j] - bmats.Ax667.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_13.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_1_17.data[i][j] - bmats.B_1_18.data[i][j] - bmats.B_1_19.data[i][j] - bmats.B_1_20.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_1_22.data[i][j] - bmats.B_1_23.data[i][j] - bmats.B_1_24.data[i][j] - bmats.B_1_25.data[i][j] - bmats.B_1_26.data[i][j] - bmats.B_1_27.data[i][j] - bmats.B_1_28.data[i][j] - bmats.B_1_29.data[i][j] - bmats.B_1_30.data[i][j] - bmats.B_1_31.data[i][j] - bmats.B_1_32.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_23_13.data[i][j] - bmats.B_24_13.data[i][j] - bmats.B_25_13.data[i][j] - bmats.B_26_13.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_29_13.data[i][j] + bmats.B_29_17.data[i][j] - bmats.B_30_13.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_32_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}