#include "fm_312.h"

inline int fm_312(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_14_7.data[i][j] - 16*bmats.A_14_8.data[i][j] - bmats.A_24_15.data[i][j] + bmats.Ax1391.data[i][j] + bmats.Ax1469.data[i][j] + bmats.Ax443.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_14.data[i][j] - bmats.B_11_14.data[i][j] - bmats.B_12_14.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_14_14.data[i][j] - bmats.B_15_14.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_1_14.data[i][j] - bmats.B_2_14.data[i][j] + bmats.B_30_8.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_4_14.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_8_17.data[i][j] - bmats.B_8_18.data[i][j] - bmats.B_8_19.data[i][j] - bmats.B_8_20.data[i][j] - bmats.B_8_21.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_8_23.data[i][j] - bmats.B_8_24.data[i][j] - bmats.B_8_25.data[i][j] - bmats.B_8_26.data[i][j] - bmats.B_8_27.data[i][j] - bmats.B_8_28.data[i][j] - bmats.B_8_29.data[i][j] - bmats.B_8_30.data[i][j] - bmats.B_8_31.data[i][j] - bmats.B_8_32.data[i][j] - bmats.B_9_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
