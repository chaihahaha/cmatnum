#include "fm_6037.h"

inline int fm_6037(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_1.data[i][j] + 16*bmats.A_17_2.data[i][j] + 16*bmats.A_2_23.data[i][j] - bmats.A_2_24.data[i][j] - 16*bmats.A_7_1.data[i][j] + bmats.A_7_2.data[i][j] - bmats.Ax3448.data[i][j] - bmats.Ax4673.data[i][j] - bmats.Ax5866.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_18.data[i][j] + bmats.B_23_1.data[i][j] + bmats.B_2_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}