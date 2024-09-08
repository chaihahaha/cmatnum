#include "fm_230.h"

inline int fm_230(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_14_15.data[i][j] - 16*bmats.A_14_16.data[i][j] - bmats.A_32_15.data[i][j] + bmats.Ax392.data[i][j] + bmats.Ax443.data[i][j] + bmats.Ax460.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_14.data[i][j] - bmats.B_11_14.data[i][j] - bmats.B_12_14.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_14_14.data[i][j] - bmats.B_15_14.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_16_17.data[i][j] - bmats.B_16_18.data[i][j] - bmats.B_16_19.data[i][j] - bmats.B_16_20.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_16_22.data[i][j] - bmats.B_16_23.data[i][j] - bmats.B_16_24.data[i][j] - bmats.B_16_25.data[i][j] - bmats.B_16_26.data[i][j] - bmats.B_16_27.data[i][j] - bmats.B_16_28.data[i][j] - bmats.B_16_29.data[i][j] - bmats.B_16_30.data[i][j] - bmats.B_16_31.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_1_14.data[i][j] - bmats.B_2_14.data[i][j] + bmats.B_30_16.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_4_14.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_9_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
