#include "fm_14798.h"

inline int fm_14798(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_10_15.data[i][j] + bmats.A_10_16.data[i][j] + 17*bmats.A_15_9.data[i][j] - 17*bmats.A_9_15.data[i][j] + bmats.Ax582.data[i][j] + bmats.Ax8484.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_11_15.data[i][j] + bmats.B_15_9.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_9_1.data[i][j] - bmats.B_9_10.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_12.data[i][j] - bmats.B_9_13.data[i][j] - bmats.B_9_14.data[i][j] - 2*bmats.B_9_15.data[i][j] - bmats.B_9_16.data[i][j] - bmats.B_9_2.data[i][j] - bmats.B_9_3.data[i][j] - bmats.B_9_4.data[i][j] - bmats.B_9_5.data[i][j] - bmats.B_9_6.data[i][j] - bmats.B_9_7.data[i][j] - bmats.B_9_8.data[i][j] - bmats.B_9_9.data[i][j] - bmats.Bx13218.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}