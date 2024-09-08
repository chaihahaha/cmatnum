#include "fm_307.h"

inline int fm_307(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_22.data[i][j] - 11*bmats.A_14_21.data[i][j] + bmats.A_14_22.data[i][j] + bmats.Ax1357.data[i][j] + bmats.Ax316.data[i][j] + bmats.Ax528.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_14.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_14_14.data[i][j] - bmats.B_15_14.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_21_1.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_21_11.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_21_2.data[i][j] - bmats.B_21_3.data[i][j] - bmats.B_21_4.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_14.data[i][j] + bmats.B_3_21.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
