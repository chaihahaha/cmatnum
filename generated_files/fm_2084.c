#include "fm_2084.h"

inline int fm_2084(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_1.data[i][j] + 11*bmats.A_16_10.data[i][j] - bmats.A_16_11.data[i][j] - bmats.A_16_2.data[i][j] - bmats.A_16_3.data[i][j] - bmats.A_16_4.data[i][j] - bmats.A_16_5.data[i][j] - bmats.A_16_6.data[i][j] - bmats.A_16_7.data[i][j] - bmats.A_16_8.data[i][j] - bmats.A_16_9.data[i][j] + bmats.A_21_12.data[i][j] + bmats.A_21_13.data[i][j] - 11*bmats.A_21_14.data[i][j] + bmats.A_21_15.data[i][j] + bmats.A_21_16.data[i][j] + bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] + bmats.A_21_21.data[i][j] + bmats.A_21_22.data[i][j] - bmats.A_3_12.data[i][j] - bmats.A_3_13.data[i][j] - bmats.A_3_14.data[i][j] - bmats.A_3_15.data[i][j] + 11*bmats.A_3_16.data[i][j] - bmats.A_3_17.data[i][j] - bmats.A_3_18.data[i][j] - bmats.A_3_19.data[i][j] - bmats.A_3_20.data[i][j] - bmats.A_3_21.data[i][j] - bmats.A_3_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_5.data[i][j]+bmats.B_10_14.data[i][j]+bmats.B_16_21.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
