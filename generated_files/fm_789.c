#include "fm_789.h"

inline int fm_789(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_15.data[i][j] - 16*bmats.A_10_16.data[i][j] - bmats.A_32_15.data[i][j] + bmats.Ax2874.data[i][j] + bmats.Ax460.data[i][j] + bmats.Ax582.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_10.data[i][j] - bmats.B_11_10.data[i][j] - bmats.B_12_10.data[i][j] - bmats.B_13_10.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_15_10.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_16_17.data[i][j] - bmats.B_16_18.data[i][j] - bmats.B_16_19.data[i][j] - bmats.B_16_20.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_16_22.data[i][j] - bmats.B_16_23.data[i][j] - bmats.B_16_24.data[i][j] - bmats.B_16_25.data[i][j] - bmats.B_16_26.data[i][j] - bmats.B_16_27.data[i][j] - bmats.B_16_28.data[i][j] - bmats.B_16_29.data[i][j] - bmats.B_16_30.data[i][j] - bmats.B_16_31.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_1_10.data[i][j] + bmats.B_26_16.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_3_10.data[i][j] - bmats.B_4_10.data[i][j] - bmats.B_5_10.data[i][j] - bmats.B_6_10.data[i][j] - bmats.B_7_10.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_9_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
