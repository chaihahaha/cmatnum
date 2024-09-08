#include "fm_1592.h"

inline int fm_1592(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_31.data[i][j] - bmats.A_12_32.data[i][j] - bmats.A_20_11.data[i][j] + 16*bmats.A_20_12.data[i][j] - bmats.A_3_3.data[i][j] + 16*bmats.A_3_4.data[i][j] - bmats.A_4_3.data[i][j] + 16*bmats.A_4_4.data[i][j] - bmats.Ax2275.data[i][j] - bmats.Ax4339.data[i][j] - bmats.Ax4363.data[i][j] - bmats.Ax4368.data[i][j] - bmats.Ax757.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_12_12.data[i][j] - bmats.B_12_14.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_12_7.data[i][j] - bmats.B_12_9.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_32_4.data[i][j] + bmats.B_4_28.data[i][j] - bmats.Bx11923.data[i][j] - bmats.Bx6289.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
