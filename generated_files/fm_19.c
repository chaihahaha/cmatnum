#include "fm_19.h"

inline int fm_19(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_18_13.data[i][j] - 11*bmats.A_18_14.data[i][j] - bmats.A_3_22.data[i][j] + bmats.Ax115.data[i][j] + bmats.Ax229.data[i][j] + bmats.Ax295.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_18.data[i][j] - bmats.B_13_18.data[i][j] - bmats.B_14_1.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_14_11.data[i][j] - bmats.B_14_18.data[i][j] - bmats.B_14_2.data[i][j] - bmats.B_14_3.data[i][j] - bmats.B_14_4.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_14_6.data[i][j] - bmats.B_14_7.data[i][j] - bmats.B_14_8.data[i][j] - bmats.B_14_9.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_16_18.data[i][j] - bmats.B_17_18.data[i][j] - bmats.B_18_18.data[i][j] - bmats.B_19_18.data[i][j] - bmats.B_20_18.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_22_18.data[i][j] + bmats.B_7_14.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
