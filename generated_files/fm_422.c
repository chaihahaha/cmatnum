#include "fm_422.h"

inline int fm_422(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_12_13.data[i][j] + bmats.A_12_14.data[i][j] + 17*bmats.A_13_14.data[i][j] - 17*bmats.A_14_13.data[i][j] + bmats.Ax1024.data[i][j] + bmats.Ax1976.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_13.data[i][j] - bmats.B_11_13.data[i][j] - bmats.B_12_13.data[i][j] - bmats.B_13_13.data[i][j] + bmats.B_13_14.data[i][j] - bmats.B_14_1.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_14_11.data[i][j] - bmats.B_14_12.data[i][j] - 2*bmats.B_14_13.data[i][j] - bmats.B_14_14.data[i][j] - bmats.B_14_15.data[i][j] - bmats.B_14_16.data[i][j] - bmats.B_14_2.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_13.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_1_13.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_4_13.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_9_13.data[i][j] - bmats.Bx3105.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
