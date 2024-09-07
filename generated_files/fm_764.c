#include "fm_764.h"

inline int fm_764(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_21_1.data[i][j] - bmats.A_21_10.data[i][j] - bmats.A_21_11.data[i][j] + 11*bmats.A_21_2.data[i][j] - bmats.A_21_3.data[i][j] - bmats.A_21_4.data[i][j] - bmats.A_21_5.data[i][j] - bmats.A_21_6.data[i][j] - bmats.A_21_7.data[i][j] - bmats.A_21_8.data[i][j] - bmats.A_21_9.data[i][j] - bmats.A_2_12.data[i][j] - bmats.A_2_13.data[i][j] + 11*bmats.A_2_14.data[i][j] - bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] - bmats.A_2_17.data[i][j] - bmats.A_2_18.data[i][j] - bmats.A_2_19.data[i][j] - bmats.A_2_20.data[i][j] - bmats.A_2_21.data[i][j] - bmats.A_2_22.data[i][j] + bmats.A_3_1.data[i][j] - 11*bmats.A_3_10.data[i][j] + bmats.A_3_11.data[i][j] + bmats.A_3_2.data[i][j] + bmats.A_3_3.data[i][j] + bmats.A_3_4.data[i][j] + bmats.A_3_5.data[i][j] + bmats.A_3_6.data[i][j] + bmats.A_3_7.data[i][j] + bmats.A_3_8.data[i][j] + bmats.A_3_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_2_3.data[i][j]+bmats.B_14_10.data[i][j]+bmats.B_10_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
