#include "fm_13720.h"

inline int fm_13720(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_5.data[i][j] + 16*bmats.A_12_6.data[i][j] - bmats.A_3_11.data[i][j] + 16*bmats.A_3_12.data[i][j] + 16*bmats.A_6_3.data[i][j] - bmats.A_6_4.data[i][j] - bmats.Ax2208.data[i][j] - bmats.Ax2445.data[i][j] - bmats.Ax4102.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_6.data[i][j] + bmats.B_3_12.data[i][j] + bmats.B_6_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
