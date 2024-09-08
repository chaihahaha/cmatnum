#include "fm_403.h"

inline int fm_403(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_13_11.data[i][j] + bmats.A_13_12.data[i][j] - bmats.A_27_16.data[i][j] + bmats.Ax1273.data[i][j] + bmats.Ax1899.data[i][j] + bmats.Ax1969.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_13.data[i][j] - bmats.B_11_13.data[i][j] - bmats.B_11_17.data[i][j] - bmats.B_11_18.data[i][j] - bmats.B_11_19.data[i][j] - bmats.B_11_20.data[i][j] - bmats.B_11_21.data[i][j] - bmats.B_11_22.data[i][j] - bmats.B_11_23.data[i][j] - bmats.B_11_24.data[i][j] - bmats.B_11_25.data[i][j] - bmats.B_11_26.data[i][j] - bmats.B_11_27.data[i][j] - bmats.B_11_28.data[i][j] - bmats.B_11_29.data[i][j] - bmats.B_11_30.data[i][j] - bmats.B_11_31.data[i][j] - bmats.B_11_32.data[i][j] - bmats.B_12_13.data[i][j] - bmats.B_13_13.data[i][j] - bmats.B_14_13.data[i][j] - bmats.B_15_13.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_1_13.data[i][j] + bmats.B_29_11.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_4_13.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_9_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
