#include "fm_506.h"

inline int fm_506(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_11.data[i][j] + 16*bmats.A_12_12.data[i][j] - bmats.A_16_31.data[i][j] - bmats.A_16_32.data[i][j] - bmats.A_28_15.data[i][j] + 16*bmats.A_28_16.data[i][j] - bmats.A_2_11.data[i][j] + 16*bmats.A_2_12.data[i][j] - bmats.Ax2175.data[i][j] - bmats.Ax2178.data[i][j] - bmats.Ax2216.data[i][j] - bmats.Ax688.data[i][j] - bmats.Ax751.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_32.data[i][j] - bmats.B_16_1.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_16_11.data[i][j] - bmats.B_16_12.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_16_16.data[i][j] - bmats.B_16_2.data[i][j] - bmats.B_16_3.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_16_6.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_16_8.data[i][j] - bmats.B_16_9.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_29_12.data[i][j] - bmats.B_30_12.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_32_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
