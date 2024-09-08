#include "fm_4749.h"

inline int fm_4749(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_23.data[i][j] + 16*bmats.A_10_24.data[i][j] + 16*bmats.A_22_10.data[i][j] - bmats.A_22_9.data[i][j] + bmats.A_8_5.data[i][j] - 16*bmats.A_8_6.data[i][j] + bmats.A_8_8.data[i][j] - bmats.Ax2819.data[i][j] - bmats.Ax3005.data[i][j] - bmats.Ax5590.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_8.data[i][j] + bmats.B_24_6.data[i][j] + bmats.B_6_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_26.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
