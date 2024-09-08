#include "fm_1557.h"

inline int fm_1557(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_14_4.data[i][j] + bmats.A_15_3.data[i][j] - 16*bmats.A_15_4.data[i][j] + 17*bmats.A_4_14.data[i][j] + bmats.Ax4407.data[i][j] + bmats.Ax944.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_4.data[i][j] - bmats.B_11_4.data[i][j] - bmats.B_12_4.data[i][j] - bmats.B_13_4.data[i][j] - bmats.B_14_12.data[i][j] - bmats.B_14_3.data[i][j] - 2*bmats.B_14_4.data[i][j] - bmats.B_14_6.data[i][j] - bmats.B_14_7.data[i][j] - bmats.B_14_8.data[i][j] - bmats.B_14_9.data[i][j] - bmats.B_15_4.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_1_4.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_3_4.data[i][j] + bmats.B_4_14.data[i][j] - bmats.B_4_4.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_6_4.data[i][j] - bmats.B_7_4.data[i][j] - bmats.B_8_4.data[i][j] - bmats.B_9_4.data[i][j] - bmats.Bx3115.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
