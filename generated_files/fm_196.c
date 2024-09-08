#include "fm_196.h"

inline int fm_196(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -12*bmats.A_10_4.data[i][j] - 11*bmats.A_11_4.data[i][j] + bmats.A_11_5.data[i][j] + 12*bmats.A_4_10.data[i][j] + bmats.Ax1184.data[i][j] + bmats.Ax891.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_1.data[i][j] - bmats.B_10_10.data[i][j] - bmats.B_10_11.data[i][j] - bmats.B_10_2.data[i][j] - bmats.B_10_3.data[i][j] - 2*bmats.B_10_4.data[i][j] - bmats.B_10_5.data[i][j] - bmats.B_10_6.data[i][j] - bmats.B_10_7.data[i][j] - bmats.B_10_8.data[i][j] - bmats.B_10_9.data[i][j] - bmats.B_11_4.data[i][j] - bmats.B_1_4.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_3_4.data[i][j] + bmats.B_4_10.data[i][j] - bmats.B_4_4.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_6_4.data[i][j] - bmats.B_7_4.data[i][j] - bmats.B_8_4.data[i][j] - bmats.B_9_4.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
