#include "fm_468.h"

inline int fm_468(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 12*bmats.A_12_21.data[i][j] - 12*bmats.A_21_12.data[i][j] + bmats.Ax1794.data[i][j] + bmats.Ax1800.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_12.data[i][j] + bmats.B_12_21.data[i][j] - bmats.B_13_12.data[i][j] - bmats.B_14_12.data[i][j] - bmats.B_15_12.data[i][j] - bmats.B_16_12.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - 2*bmats.B_21_12.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_21_15.data[i][j] - bmats.B_21_16.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_21_21.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_22_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
