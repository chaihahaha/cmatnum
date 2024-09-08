#include "fm_402.h"

inline int fm_402(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_32.data[i][j] - 16*bmats.A_29_27.data[i][j] + bmats.A_29_28.data[i][j] + bmats.Ax1252.data[i][j] + bmats.Ax1867.data[i][j] + bmats.Ax1966.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_27.data[i][j] - bmats.B_17_29.data[i][j] - bmats.B_18_29.data[i][j] - bmats.B_19_29.data[i][j] - bmats.B_20_29.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_22_29.data[i][j] - bmats.B_23_29.data[i][j] - bmats.B_24_29.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_26_29.data[i][j] - bmats.B_27_1.data[i][j] - bmats.B_27_10.data[i][j] - bmats.B_27_11.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_27_14.data[i][j] - bmats.B_27_15.data[i][j] - bmats.B_27_16.data[i][j] - bmats.B_27_2.data[i][j] - bmats.B_27_29.data[i][j] - bmats.B_27_3.data[i][j] - bmats.B_27_4.data[i][j] - bmats.B_27_5.data[i][j] - bmats.B_27_6.data[i][j] - bmats.B_27_7.data[i][j] - bmats.B_27_8.data[i][j] - bmats.B_27_9.data[i][j] - bmats.B_28_29.data[i][j] - bmats.B_29_29.data[i][j] - bmats.B_30_29.data[i][j] - bmats.B_31_29.data[i][j] - bmats.B_32_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
