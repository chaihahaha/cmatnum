#include "fm_943.h"

inline int fm_943(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_18_25.data[i][j] - bmats.A_18_26.data[i][j] - bmats.A_25_15.data[i][j] - bmats.A_25_16.data[i][j] + 16*bmats.A_25_25.data[i][j] - bmats.A_25_26.data[i][j] + 16*bmats.A_9_25.data[i][j] - bmats.A_9_26.data[i][j] - bmats.Ax242.data[i][j] - bmats.Ax280.data[i][j] - bmats.Ax2848.data[i][j] - bmats.Ax3220.data[i][j] - bmats.Ax700.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_25.data[i][j] - bmats.B_11_25.data[i][j] - bmats.B_12_25.data[i][j] - bmats.B_13_25.data[i][j] - bmats.B_14_25.data[i][j] - bmats.B_15_25.data[i][j] - bmats.B_16_25.data[i][j] - bmats.B_1_25.data[i][j] - bmats.B_25_17.data[i][j] - bmats.B_25_18.data[i][j] - bmats.B_25_19.data[i][j] - bmats.B_25_20.data[i][j] - bmats.B_25_21.data[i][j] - bmats.B_25_22.data[i][j] - bmats.B_25_23.data[i][j] - bmats.B_25_24.data[i][j] - bmats.B_25_25.data[i][j] - bmats.B_25_26.data[i][j] - bmats.B_25_27.data[i][j] - bmats.B_25_28.data[i][j] - bmats.B_25_29.data[i][j] - bmats.B_25_30.data[i][j] - bmats.B_25_31.data[i][j] - bmats.B_25_32.data[i][j] + bmats.B_25_9.data[i][j] - bmats.B_2_25.data[i][j] - bmats.B_3_25.data[i][j] - bmats.B_4_25.data[i][j] - bmats.B_5_25.data[i][j] - bmats.B_6_25.data[i][j] - bmats.B_7_25.data[i][j] - bmats.B_8_25.data[i][j] - bmats.B_9_25.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_25.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}