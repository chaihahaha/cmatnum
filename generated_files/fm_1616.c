#include "fm_1616.h"

inline int fm_1616(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_10.data[i][j] + 16*bmats.A_20_9.data[i][j] - bmats.A_3_3.data[i][j] + 16*bmats.A_3_4.data[i][j] - bmats.A_4_3.data[i][j] + 16*bmats.A_4_4.data[i][j] - bmats.A_9_31.data[i][j] - bmats.A_9_32.data[i][j] - bmats.Ax2828.data[i][j] - bmats.Ax4339.data[i][j] - bmats.Ax4363.data[i][j] - bmats.Ax4368.data[i][j] - bmats.Ax769.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_32_4.data[i][j] + bmats.B_4_25.data[i][j] - bmats.B_9_1.data[i][j] - bmats.B_9_10.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_12.data[i][j] - bmats.B_9_13.data[i][j] - bmats.B_9_14.data[i][j] - bmats.B_9_15.data[i][j] - bmats.B_9_16.data[i][j] - bmats.B_9_2.data[i][j] - bmats.B_9_3.data[i][j] - bmats.B_9_4.data[i][j] - bmats.B_9_5.data[i][j] - bmats.B_9_6.data[i][j] - bmats.B_9_7.data[i][j] - bmats.B_9_8.data[i][j] - bmats.B_9_9.data[i][j] - bmats.Bx11923.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
