#include "fm_13309.h"

inline int fm_13309(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_16_15.data[i][j] + bmats.A_16_16.data[i][j] - bmats.A_31_3.data[i][j] + bmats.Ax1152.data[i][j] + bmats.Ax463.data[i][j] + bmats.Ax7798.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_16.data[i][j] - bmats.B_12_16.data[i][j] - bmats.B_15_16.data[i][j] - bmats.B_15_17.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_15_20.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_15_25.data[i][j] - bmats.B_15_26.data[i][j] - bmats.B_15_27.data[i][j] - bmats.B_15_28.data[i][j] - bmats.B_15_29.data[i][j] - bmats.B_15_30.data[i][j] - bmats.B_15_31.data[i][j] - bmats.B_15_32.data[i][j] - bmats.B_1_16.data[i][j] - bmats.B_2_16.data[i][j] + bmats.B_32_15.data[i][j] - bmats.B_3_16.data[i][j] - bmats.B_5_16.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_9_16.data[i][j] - bmats.Bx13355.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}