#include "fm_1620.h"

inline int fm_1620(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_16.data[i][j] - 16*bmats.A_4_3.data[i][j] + bmats.A_4_4.data[i][j] + bmats.Ax4329.data[i][j] + bmats.Ax4363.data[i][j] + bmats.Ax962.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_13_4.data[i][j] - bmats.B_14_4.data[i][j] - bmats.B_15_4.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_1_4.data[i][j] + bmats.B_20_3.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_3_18.data[i][j] - bmats.B_3_19.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_3_25.data[i][j] - bmats.B_3_26.data[i][j] - bmats.B_3_27.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_3_29.data[i][j] - bmats.B_3_30.data[i][j] - bmats.B_3_31.data[i][j] - bmats.B_3_32.data[i][j] - bmats.B_3_4.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_6_4.data[i][j] - bmats.B_9_4.data[i][j] - bmats.Bx11903.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}