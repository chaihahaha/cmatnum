#include "fm_419.h"

inline int fm_419(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_13_13.data[i][j] + bmats.A_13_14.data[i][j] - bmats.A_29_14.data[i][j] + bmats.Ax1027.data[i][j] + bmats.Ax1899.data[i][j] + bmats.Ax983.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_13.data[i][j] - bmats.B_11_13.data[i][j] - bmats.B_12_13.data[i][j] - bmats.B_13_13.data[i][j] - bmats.B_13_17.data[i][j] - bmats.B_13_18.data[i][j] - bmats.B_13_19.data[i][j] - bmats.B_13_20.data[i][j] - bmats.B_13_21.data[i][j] - bmats.B_13_22.data[i][j] - bmats.B_13_23.data[i][j] - bmats.B_13_24.data[i][j] - bmats.B_13_25.data[i][j] - bmats.B_13_26.data[i][j] - bmats.B_13_27.data[i][j] - bmats.B_13_28.data[i][j] - bmats.B_13_29.data[i][j] - bmats.B_13_30.data[i][j] - bmats.B_13_31.data[i][j] - bmats.B_13_32.data[i][j] - bmats.B_14_13.data[i][j] - bmats.B_15_13.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_1_13.data[i][j] + bmats.B_29_13.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_4_13.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_9_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}