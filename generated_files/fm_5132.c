#include "fm_5132.h"

inline int fm_5132(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_31.data[i][j] + 16*bmats.A_10_32.data[i][j] + bmats.A_16_16.data[i][j] + bmats.A_16_3.data[i][j] - 16*bmats.A_16_4.data[i][j] + 16*bmats.A_20_10.data[i][j] - bmats.A_20_9.data[i][j] - bmats.Ax2828.data[i][j] - bmats.Ax5685.data[i][j] - bmats.Ax772.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_16.data[i][j] + bmats.B_32_4.data[i][j] + bmats.B_4_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_26.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}