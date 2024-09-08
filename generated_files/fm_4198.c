#include "fm_4198.h"

inline int fm_4198(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_11.data[i][j] - 11*bmats.A_7_8.data[i][j] + bmats.A_7_9.data[i][j] + bmats.Ax164.data[i][j] + bmats.Ax3130.data[i][j] + bmats.Ax694.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_18_8.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_6_7.data[i][j] - bmats.B_7_7.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_8_17.data[i][j] - bmats.B_8_18.data[i][j] - bmats.B_8_19.data[i][j] - bmats.B_8_20.data[i][j] - bmats.B_8_21.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_9_7.data[i][j] - bmats.Bx4249.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
