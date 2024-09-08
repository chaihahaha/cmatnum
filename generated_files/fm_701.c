#include "fm_701.h"

inline int fm_701(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_23_31.data[i][j] - bmats.A_23_32.data[i][j] - 16*bmats.A_27_7.data[i][j] + bmats.A_27_8.data[i][j] - bmats.Ax2735.data[i][j] - bmats.Ax618.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_11.data[i][j] - bmats.B_18_11.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_20_11.data[i][j] - bmats.B_21_11.data[i][j] - bmats.B_22_11.data[i][j] - bmats.B_23_11.data[i][j] - bmats.B_24_11.data[i][j] - bmats.B_25_11.data[i][j] - bmats.B_26_11.data[i][j] - bmats.B_27_11.data[i][j] + bmats.B_27_23.data[i][j] - bmats.B_28_11.data[i][j] - bmats.B_29_11.data[i][j] - bmats.B_30_11.data[i][j] - bmats.B_31_11.data[i][j] - bmats.B_32_11.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_7_18.data[i][j] - bmats.B_7_19.data[i][j] - bmats.B_7_20.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_7_23.data[i][j] - bmats.B_7_24.data[i][j] - bmats.B_7_25.data[i][j] - bmats.B_7_26.data[i][j] - bmats.B_7_27.data[i][j] - bmats.B_7_28.data[i][j] - bmats.B_7_29.data[i][j] - bmats.B_7_30.data[i][j] - bmats.B_7_31.data[i][j] - bmats.B_7_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
