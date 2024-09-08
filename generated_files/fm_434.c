#include "fm_434.h"

inline int fm_434(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_29_25.data[i][j] + bmats.A_29_26.data[i][j] - bmats.A_9_30.data[i][j] + bmats.Ax1512.data[i][j] + bmats.Ax1867.data[i][j] + bmats.Ax2050.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_25.data[i][j] - bmats.B_17_29.data[i][j] - bmats.B_18_29.data[i][j] - bmats.B_19_29.data[i][j] - bmats.B_20_29.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_22_29.data[i][j] - bmats.B_23_29.data[i][j] - bmats.B_24_29.data[i][j] - bmats.B_25_1.data[i][j] - bmats.B_25_10.data[i][j] - bmats.B_25_11.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_25_13.data[i][j] - bmats.B_25_14.data[i][j] - bmats.B_25_15.data[i][j] - bmats.B_25_16.data[i][j] - bmats.B_25_2.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_25_3.data[i][j] - bmats.B_25_4.data[i][j] - bmats.B_25_5.data[i][j] - bmats.B_25_6.data[i][j] - bmats.B_25_7.data[i][j] - bmats.B_25_8.data[i][j] - bmats.B_25_9.data[i][j] - bmats.B_26_29.data[i][j] - bmats.B_27_29.data[i][j] - bmats.B_28_29.data[i][j] - bmats.B_29_29.data[i][j] - bmats.B_30_29.data[i][j] - bmats.B_31_29.data[i][j] - bmats.B_32_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
