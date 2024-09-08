#include "fm_249.h"

inline int fm_249(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_15_3.data[i][j] - 17*bmats.A_3_15.data[i][j] - 16*bmats.A_4_15.data[i][j] + bmats.A_4_16.data[i][j] + bmats.Ax588.data[i][j] + bmats.Ax908.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_15.data[i][j] - bmats.B_11_15.data[i][j] - bmats.B_12_15.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_14_15.data[i][j] - bmats.B_15_15.data[i][j] + bmats.B_15_3.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_1_15.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_3_1.data[i][j] - bmats.B_3_10.data[i][j] - bmats.B_3_11.data[i][j] - bmats.B_3_12.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_3_14.data[i][j] - 2*bmats.B_3_15.data[i][j] - bmats.B_3_16.data[i][j] - bmats.B_3_2.data[i][j] - bmats.B_3_3.data[i][j] - bmats.B_3_4.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_3_6.data[i][j] - bmats.B_3_7.data[i][j] - bmats.B_3_8.data[i][j] - bmats.B_3_9.data[i][j] - bmats.B_4_15.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_6_15.data[i][j] - bmats.B_7_15.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_9_15.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
