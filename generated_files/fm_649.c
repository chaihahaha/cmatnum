#include "fm_649.h"

inline int fm_649(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_11_13.data[i][j] + bmats.A_11_14.data[i][j] - bmats.A_29_14.data[i][j] + bmats.Ax1021.data[i][j] + bmats.Ax2627.data[i][j] + bmats.Ax983.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_11.data[i][j] - bmats.B_11_11.data[i][j] - bmats.B_12_11.data[i][j] - bmats.B_13_11.data[i][j] - bmats.B_14_11.data[i][j] - bmats.B_15_11.data[i][j] - bmats.B_16_11.data[i][j] - bmats.B_1_11.data[i][j] + bmats.B_27_13.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_3_11.data[i][j] - bmats.B_4_11.data[i][j] - bmats.B_5_11.data[i][j] - bmats.B_6_11.data[i][j] - bmats.B_7_11.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_9_11.data[i][j] - bmats.Bx4641.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}