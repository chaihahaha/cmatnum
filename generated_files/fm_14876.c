#include "fm_14876.h"

inline int fm_14876(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_16_17.data[i][j] - 16*bmats.A_16_18.data[i][j] - bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] - bmats.Ax556.data[i][j] - bmats.Ax8496.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_32.data[i][j] - bmats.B_11_32.data[i][j] - bmats.B_12_32.data[i][j] - bmats.B_13_32.data[i][j] - bmats.B_14_32.data[i][j] - bmats.B_15_32.data[i][j] + bmats.B_16_2.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_18_1.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_18_11.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_18_15.data[i][j] - bmats.B_18_16.data[i][j] - bmats.B_18_2.data[i][j] - bmats.B_18_3.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_1_32.data[i][j] - bmats.B_2_32.data[i][j] - bmats.B_3_32.data[i][j] - bmats.B_4_32.data[i][j] - bmats.B_5_32.data[i][j] - bmats.B_6_32.data[i][j] - bmats.B_7_32.data[i][j] - bmats.B_8_32.data[i][j] - bmats.B_9_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
