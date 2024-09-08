#include "fm_926.h"

inline int fm_926(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_31.data[i][j] - bmats.A_13_32.data[i][j] + 16*bmats.A_25_13.data[i][j] - bmats.A_25_14.data[i][j] - bmats.A_2_10.data[i][j] + 16*bmats.A_2_9.data[i][j] - bmats.A_9_10.data[i][j] + 16*bmats.A_9_9.data[i][j] - bmats.Ax2923.data[i][j] - bmats.Ax2944.data[i][j] - bmats.Ax3213.data[i][j] - bmats.Ax506.data[i][j] - bmats.Ax760.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_13_11.data[i][j] - bmats.B_13_12.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_13_16.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_23_9.data[i][j] - bmats.B_24_9.data[i][j] - bmats.B_25_9.data[i][j] - bmats.B_26_9.data[i][j] - bmats.B_27_9.data[i][j] - bmats.B_28_9.data[i][j] - bmats.B_29_9.data[i][j] - bmats.B_30_9.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_32_9.data[i][j] + bmats.B_9_29.data[i][j] - bmats.Bx4615.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
