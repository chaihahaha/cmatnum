#include "fm_14778.h"

inline int fm_14778(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_31_21.data[i][j] - 16*bmats.A_31_22.data[i][j] - bmats.A_6_30.data[i][j] + bmats.Ax1710.data[i][j] + bmats.Ax3930.data[i][j] + bmats.Ax722.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_22.data[i][j] - bmats.B_18_31.data[i][j] - bmats.B_19_31.data[i][j] - bmats.B_20_31.data[i][j] - bmats.B_21_31.data[i][j] - bmats.B_22_1.data[i][j] - bmats.B_22_10.data[i][j] - bmats.B_22_11.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_22_15.data[i][j] - bmats.B_22_16.data[i][j] - bmats.B_22_2.data[i][j] - bmats.B_22_3.data[i][j] - bmats.B_22_31.data[i][j] - bmats.B_22_4.data[i][j] - bmats.B_22_5.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_22_7.data[i][j] - bmats.B_22_8.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_23_31.data[i][j] - bmats.B_24_31.data[i][j] - bmats.B_30_31.data[i][j] - bmats.B_31_31.data[i][j] - bmats.Bx13390.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
