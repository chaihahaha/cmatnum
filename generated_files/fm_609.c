#include "fm_609.h"

inline int fm_609(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_12_19.data[i][j] - 16*bmats.A_12_20.data[i][j] - bmats.A_4_15.data[i][j] - bmats.A_4_16.data[i][j] - bmats.Ax2491.data[i][j] - bmats.Ax588.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_28.data[i][j] - bmats.B_11_28.data[i][j] - bmats.B_12_28.data[i][j] + bmats.B_12_4.data[i][j] - bmats.B_13_28.data[i][j] - bmats.B_14_28.data[i][j] - bmats.B_15_28.data[i][j] - bmats.B_16_28.data[i][j] - bmats.B_1_28.data[i][j] - bmats.B_20_1.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_20_11.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_20_15.data[i][j] - bmats.B_20_16.data[i][j] - bmats.B_20_2.data[i][j] - bmats.B_20_3.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_20_5.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_2_28.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_4_28.data[i][j] - bmats.B_5_28.data[i][j] - bmats.B_6_28.data[i][j] - bmats.B_7_28.data[i][j] - bmats.B_8_28.data[i][j] - bmats.B_9_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
