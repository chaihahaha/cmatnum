#include "fm_1644.h"

inline int fm_1644(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_31.data[i][j] + bmats.A_19_31.data[i][j] - 16*bmats.A_19_32.data[i][j] + bmats.Ax1186.data[i][j] + bmats.Ax4508.data[i][j] + bmats.Ax630.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_19.data[i][j] - bmats.B_18_19.data[i][j] - bmats.B_19_19.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_22_19.data[i][j] - bmats.B_23_19.data[i][j] - bmats.B_24_19.data[i][j] - bmats.B_25_19.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_28_19.data[i][j] - bmats.B_29_19.data[i][j] - bmats.B_30_19.data[i][j] - bmats.B_31_19.data[i][j] - bmats.B_32_1.data[i][j] - bmats.B_32_10.data[i][j] - bmats.B_32_11.data[i][j] - bmats.B_32_12.data[i][j] - bmats.B_32_13.data[i][j] - bmats.B_32_14.data[i][j] - bmats.B_32_15.data[i][j] - bmats.B_32_16.data[i][j] - bmats.B_32_19.data[i][j] - bmats.B_32_2.data[i][j] - bmats.B_32_3.data[i][j] - bmats.B_32_4.data[i][j] - bmats.B_32_5.data[i][j] - bmats.B_32_6.data[i][j] - bmats.B_32_7.data[i][j] - bmats.B_32_8.data[i][j] - bmats.B_32_9.data[i][j] + bmats.B_3_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}