#include "fm_881.h"

inline int fm_881(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_31.data[i][j] - bmats.A_19_32.data[i][j] + bmats.A_26_1.data[i][j] + bmats.A_26_10.data[i][j] + bmats.A_26_11.data[i][j] + bmats.A_26_12.data[i][j] + bmats.A_26_13.data[i][j] + bmats.A_26_14.data[i][j] + bmats.A_26_15.data[i][j] + bmats.A_26_16.data[i][j] + bmats.A_26_2.data[i][j] - 16*bmats.A_26_3.data[i][j] + bmats.A_26_4.data[i][j] + bmats.A_26_5.data[i][j] + bmats.A_26_6.data[i][j] + bmats.A_26_7.data[i][j] + bmats.A_26_8.data[i][j] + bmats.A_26_9.data[i][j] - bmats.Ax2874.data[i][j] - bmats.Ax630.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_10.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_22_10.data[i][j] - bmats.B_23_10.data[i][j] - bmats.B_24_10.data[i][j] - bmats.B_25_10.data[i][j] - bmats.B_26_10.data[i][j] + bmats.B_26_19.data[i][j] - bmats.B_27_10.data[i][j] - bmats.B_28_10.data[i][j] - bmats.B_29_10.data[i][j] - bmats.B_30_10.data[i][j] - bmats.B_31_10.data[i][j] - bmats.B_32_10.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_3_18.data[i][j] - bmats.B_3_19.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_3_25.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_3_27.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_3_30.data[i][j] - bmats.B_3_31.data[i][j] - bmats.B_3_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
