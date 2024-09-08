#include "fm_12057.h"

inline int fm_12057(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_15.data[i][j] + 16*bmats.A_17_16.data[i][j] + bmats.A_32_22.data[i][j] - 16*bmats.A_32_23.data[i][j] + bmats.A_32_28.data[i][j] + bmats.A_32_29.data[i][j] + bmats.A_32_32.data[i][j] + 16*bmats.A_7_17.data[i][j] - bmats.A_7_18.data[i][j] - bmats.Ax3878.data[i][j] - bmats.Ax5998.data[i][j] - bmats.Ax660.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_23.data[i][j] + bmats.B_17_32.data[i][j] + bmats.B_23_1.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
