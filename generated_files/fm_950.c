#include "fm_950.h"

inline int fm_950(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_31.data[i][j] - bmats.A_10_32.data[i][j] + 16*bmats.A_25_10.data[i][j] - bmats.A_25_9.data[i][j] - bmats.A_2_10.data[i][j] + 16*bmats.A_2_9.data[i][j] - bmats.A_9_10.data[i][j] + 16*bmats.A_9_9.data[i][j] - bmats.Ax2810.data[i][j] - bmats.Ax2923.data[i][j] - bmats.Ax2944.data[i][j] - bmats.Ax3213.data[i][j] - bmats.Ax772.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_1.data[i][j] - bmats.B_10_10.data[i][j] - bmats.B_10_11.data[i][j] - bmats.B_10_12.data[i][j] - bmats.B_10_13.data[i][j] - bmats.B_10_14.data[i][j] - bmats.B_10_15.data[i][j] - bmats.B_10_16.data[i][j] - bmats.B_10_2.data[i][j] - bmats.B_10_3.data[i][j] - bmats.B_10_4.data[i][j] - bmats.B_10_5.data[i][j] - bmats.B_10_6.data[i][j] - bmats.B_10_7.data[i][j] - bmats.B_10_8.data[i][j] - bmats.B_10_9.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_23_9.data[i][j] - bmats.B_24_9.data[i][j] - bmats.B_25_9.data[i][j] - bmats.B_26_9.data[i][j] - bmats.B_27_9.data[i][j] - bmats.B_28_9.data[i][j] - bmats.B_29_9.data[i][j] - bmats.B_30_9.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_32_9.data[i][j] + bmats.B_9_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
