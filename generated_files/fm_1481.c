#include "fm_1481.h"

inline int fm_1481(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_5_21.data[i][j] - 16*bmats.A_5_22.data[i][j] - bmats.A_6_15.data[i][j] - bmats.A_6_16.data[i][j] - bmats.Ax4218.data[i][j] - bmats.Ax594.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_21.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_22_1.data[i][j] - bmats.B_22_10.data[i][j] - bmats.B_22_11.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_22_15.data[i][j] - bmats.B_22_16.data[i][j] - bmats.B_22_2.data[i][j] - bmats.B_22_3.data[i][j] - bmats.B_22_4.data[i][j] - bmats.B_22_5.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_22_7.data[i][j] - bmats.B_22_8.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_4_21.data[i][j] - bmats.B_5_21.data[i][j] + bmats.B_5_6.data[i][j] - bmats.B_8_21.data[i][j] - bmats.Bx11715.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
