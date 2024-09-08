#include "fm_270.h"

inline int fm_270(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_19.data[i][j] - 16*bmats.A_30_31.data[i][j] + bmats.A_30_32.data[i][j] + bmats.Ax1150.data[i][j] + bmats.Ax529.data[i][j] + bmats.Ax604.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_31.data[i][j] - bmats.B_17_30.data[i][j] - bmats.B_18_30.data[i][j] - bmats.B_19_30.data[i][j] - bmats.B_20_30.data[i][j] - bmats.B_21_30.data[i][j] - bmats.B_22_30.data[i][j] - bmats.B_23_30.data[i][j] - bmats.B_24_30.data[i][j] - bmats.B_25_30.data[i][j] - bmats.B_26_30.data[i][j] - bmats.B_27_30.data[i][j] - bmats.B_28_30.data[i][j] - bmats.B_29_30.data[i][j] - bmats.B_30_30.data[i][j] - bmats.B_31_1.data[i][j] - bmats.B_31_10.data[i][j] - bmats.B_31_11.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_31_14.data[i][j] - bmats.B_31_15.data[i][j] - bmats.B_31_16.data[i][j] - bmats.B_31_2.data[i][j] - bmats.B_31_3.data[i][j] - bmats.B_31_30.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_31_5.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_31_7.data[i][j] - bmats.B_31_8.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_32_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
