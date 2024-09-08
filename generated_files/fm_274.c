#include "fm_274.h"

inline int fm_274(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_20.data[i][j] + bmats.Ax1239.data[i][j] + bmats.Ax127.data[i][j] + bmats.Ax1393.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_1.data[i][j] - bmats.B_12_10.data[i][j] - bmats.B_12_11.data[i][j] - bmats.B_12_15.data[i][j] - bmats.B_12_2.data[i][j] - bmats.B_12_3.data[i][j] - bmats.B_12_4.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_12_6.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_12_8.data[i][j] - bmats.B_12_9.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_14_15.data[i][j] - bmats.B_15_15.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_18_15.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_20_15.data[i][j] - bmats.B_21_15.data[i][j] - bmats.B_22_15.data[i][j] + bmats.B_4_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
