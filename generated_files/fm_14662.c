#include "fm_14662.h"

inline int fm_14662(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_22_10.data[i][j] - bmats.A_22_9.data[i][j] + bmats.A_26_18.data[i][j] + bmats.A_26_20.data[i][j] + bmats.A_26_22.data[i][j] + bmats.A_26_23.data[i][j] - 16*bmats.A_26_24.data[i][j] + bmats.A_26_26.data[i][j] + bmats.A_26_28.data[i][j] + bmats.A_26_29.data[i][j] + bmats.A_26_30.data[i][j] - bmats.A_8_21.data[i][j] + 16*bmats.A_8_22.data[i][j] - bmats.Ax2819.data[i][j] - bmats.Ax3538.data[i][j] - bmats.Ax8346.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_24.data[i][j] + bmats.B_22_26.data[i][j] + bmats.B_24_6.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
