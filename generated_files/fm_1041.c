#include "fm_1041.h"

inline int fm_1041(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_31.data[i][j] - bmats.A_13_32.data[i][j] + 16*bmats.A_24_13.data[i][j] - bmats.A_24_14.data[i][j] - bmats.A_3_7.data[i][j] + 16*bmats.A_3_8.data[i][j] - bmats.A_8_7.data[i][j] + 16*bmats.A_8_8.data[i][j] - bmats.Ax3461.data[i][j] - bmats.Ax3486.data[i][j] - bmats.Ax3491.data[i][j] - bmats.Ax503.data[i][j] - bmats.Ax760.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_13_11.data[i][j] - bmats.B_13_12.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_13_16.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_17_8.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_22_8.data[i][j] - bmats.B_23_8.data[i][j] - bmats.B_24_8.data[i][j] - bmats.B_25_8.data[i][j] - bmats.B_26_8.data[i][j] - bmats.B_27_8.data[i][j] - bmats.B_28_8.data[i][j] - bmats.B_29_8.data[i][j] - bmats.B_30_8.data[i][j] - bmats.B_31_8.data[i][j] - bmats.B_32_8.data[i][j] + bmats.B_8_29.data[i][j] - bmats.Bx4615.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_8.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}