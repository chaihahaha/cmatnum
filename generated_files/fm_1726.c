#include "fm_1726.h"

inline int fm_1726(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_19_23.data[i][j] - 16*bmats.A_19_24.data[i][j] - bmats.A_8_31.data[i][j] + bmats.Ax1449.data[i][j] + bmats.Ax343.data[i][j] + bmats.Ax4508.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_19.data[i][j] - bmats.B_18_19.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_23_19.data[i][j] - bmats.B_24_1.data[i][j] - bmats.B_24_19.data[i][j] - bmats.B_24_2.data[i][j] - bmats.B_24_3.data[i][j] - bmats.B_24_4.data[i][j] - bmats.B_24_5.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_30_19.data[i][j] - bmats.B_32_19.data[i][j] + bmats.B_3_24.data[i][j] - bmats.Bx12409.data[i][j] - bmats.Bx9722.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
