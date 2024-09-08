#include "fm_527.h"

inline int fm_527(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_4.data[i][j] + 11*bmats.A_12_5.data[i][j] - bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j] - bmats.Ax1804.data[i][j] - bmats.Ax1807.data[i][j] - bmats.Ax786.data[i][j] - bmats.Ax947.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_1.data[i][j] - bmats.B_13_1.data[i][j] - bmats.B_14_1.data[i][j] - bmats.B_15_1.data[i][j] - bmats.B_16_1.data[i][j] - bmats.B_17_1.data[i][j] - bmats.B_18_1.data[i][j] - bmats.B_19_1.data[i][j] + bmats.B_1_16.data[i][j] - bmats.B_20_1.data[i][j] - bmats.B_21_1.data[i][j] - bmats.B_22_1.data[i][j] - bmats.B_5_1.data[i][j] - bmats.B_5_10.data[i][j] - bmats.B_5_11.data[i][j] - bmats.B_5_2.data[i][j] - bmats.B_5_3.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_5_6.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_5_8.data[i][j] - bmats.B_5_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
