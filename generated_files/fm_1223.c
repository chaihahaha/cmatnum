#include "fm_1223.h"

inline int fm_1223(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_19_23.data[i][j] - bmats.A_19_24.data[i][j] + 16*bmats.A_23_23.data[i][j] - bmats.A_23_24.data[i][j] - bmats.A_25_15.data[i][j] - bmats.A_25_16.data[i][j] + 16*bmats.A_7_25.data[i][j] - bmats.A_7_26.data[i][j] - bmats.Ax2860.data[i][j] - bmats.Ax343.data[i][j] - bmats.Ax357.data[i][j] - bmats.Ax3669.data[i][j] - bmats.Ax700.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_12_23.data[i][j] - bmats.B_13_23.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_16_23.data[i][j] - bmats.B_1_23.data[i][j] + bmats.B_23_9.data[i][j] - bmats.B_25_17.data[i][j] - bmats.B_25_21.data[i][j] - bmats.B_25_25.data[i][j] - bmats.B_25_27.data[i][j] - bmats.B_25_28.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_25_30.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_4_23.data[i][j] - bmats.B_5_23.data[i][j] - bmats.B_6_23.data[i][j] - bmats.Bx10243.data[i][j] - bmats.Bx9522.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}