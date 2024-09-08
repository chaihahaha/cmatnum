#include "fm_1002.h"

inline int fm_1002(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_25_19.data[i][j] - 16*bmats.A_25_20.data[i][j] - bmats.A_4_31.data[i][j] + bmats.Ax123.data[i][j] + bmats.Ax1587.data[i][j] + bmats.Ax3157.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_25.data[i][j] - bmats.B_18_25.data[i][j] - bmats.B_19_25.data[i][j] - bmats.B_20_1.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_20_11.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_20_15.data[i][j] - bmats.B_20_16.data[i][j] - bmats.B_20_2.data[i][j] - bmats.B_20_25.data[i][j] - bmats.B_20_3.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_20_5.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_25.data[i][j] - bmats.B_22_25.data[i][j] - bmats.B_23_25.data[i][j] - bmats.B_24_25.data[i][j] - bmats.B_25_25.data[i][j] - bmats.B_26_25.data[i][j] - bmats.B_27_25.data[i][j] - bmats.B_28_25.data[i][j] - bmats.B_29_25.data[i][j] - bmats.B_30_25.data[i][j] - bmats.B_31_25.data[i][j] - bmats.B_32_25.data[i][j] + bmats.B_9_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_25.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
