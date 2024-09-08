#include "fm_4177.h"

inline int fm_4177(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -12*bmats.A_1_8.data[i][j] - 11*bmats.A_2_8.data[i][j] + bmats.A_2_9.data[i][j] + 12*bmats.A_8_1.data[i][j] + bmats.Ax1679.data[i][j] + bmats.Ax3297.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_8.data[i][j] - bmats.B_11_8.data[i][j] - bmats.B_1_1.data[i][j] - bmats.B_1_10.data[i][j] - bmats.B_1_11.data[i][j] - bmats.B_1_2.data[i][j] - bmats.B_1_3.data[i][j] - bmats.B_1_4.data[i][j] - bmats.B_1_5.data[i][j] - bmats.B_1_6.data[i][j] - bmats.B_1_7.data[i][j] - 2*bmats.B_1_8.data[i][j] - bmats.B_1_9.data[i][j] - bmats.B_2_8.data[i][j] - bmats.B_3_8.data[i][j] - bmats.B_4_8.data[i][j] - bmats.B_5_8.data[i][j] - bmats.B_6_8.data[i][j] - bmats.B_7_8.data[i][j] + bmats.B_8_1.data[i][j] - bmats.B_8_8.data[i][j] - bmats.B_9_8.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
