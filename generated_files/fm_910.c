#include "fm_910.h"

inline int fm_910(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_17.data[i][j] - bmats.A_10_18.data[i][j] - bmats.A_17_15.data[i][j] - bmats.A_17_16.data[i][j] - bmats.A_17_25.data[i][j] + 16*bmats.A_17_26.data[i][j] - bmats.A_26_25.data[i][j] + 16*bmats.A_26_26.data[i][j] - bmats.Ax239.data[i][j] - bmats.Ax2963.data[i][j] - bmats.Ax3111.data[i][j] - bmats.Ax58.data[i][j] - bmats.Ax660.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_26.data[i][j] - bmats.B_11_26.data[i][j] - bmats.B_12_26.data[i][j] - bmats.B_13_26.data[i][j] - bmats.B_14_26.data[i][j] - bmats.B_15_26.data[i][j] - bmats.B_16_26.data[i][j] - bmats.B_17_17.data[i][j] - bmats.B_17_18.data[i][j] - bmats.B_17_19.data[i][j] - bmats.B_17_20.data[i][j] - bmats.B_17_21.data[i][j] - bmats.B_17_22.data[i][j] - bmats.B_17_23.data[i][j] - bmats.B_17_24.data[i][j] - bmats.B_17_25.data[i][j] - bmats.B_17_26.data[i][j] - bmats.B_17_27.data[i][j] - bmats.B_17_28.data[i][j] - bmats.B_17_29.data[i][j] - bmats.B_17_30.data[i][j] - bmats.B_17_31.data[i][j] - bmats.B_17_32.data[i][j] - bmats.B_1_26.data[i][j] + bmats.B_26_1.data[i][j] - bmats.B_2_26.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_4_26.data[i][j] - bmats.B_5_26.data[i][j] - bmats.B_6_26.data[i][j] - bmats.B_7_26.data[i][j] - bmats.B_8_26.data[i][j] - bmats.B_9_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
