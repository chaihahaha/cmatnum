#include "fm_366.h"

inline int fm_366(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_21_10.data[i][j] - 11*bmats.A_2_10.data[i][j] + bmats.A_2_11.data[i][j] + bmats.Ax1582.data[i][j] + bmats.Ax261.data[i][j] + bmats.Ax544.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_12.data[i][j] - bmats.B_10_13.data[i][j] - bmats.B_10_14.data[i][j] - bmats.B_10_15.data[i][j] - bmats.B_10_16.data[i][j] - bmats.B_10_17.data[i][j] - bmats.B_10_18.data[i][j] - bmats.B_10_19.data[i][j] - bmats.B_10_2.data[i][j] - bmats.B_10_20.data[i][j] - bmats.B_10_21.data[i][j] - bmats.B_10_22.data[i][j] - bmats.B_11_2.data[i][j] + bmats.B_13_10.data[i][j] - bmats.B_1_2.data[i][j] - bmats.B_2_2.data[i][j] - bmats.B_3_2.data[i][j] - bmats.B_4_2.data[i][j] - bmats.B_5_2.data[i][j] - bmats.B_6_2.data[i][j] - bmats.B_7_2.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_9_2.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
