#include "fm_2096.h"

inline int fm_2096(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_13_15.data[i][j] - 16*bmats.A_13_16.data[i][j] - bmats.A_32_10.data[i][j] + 16*bmats.A_32_9.data[i][j] + 16*bmats.A_9_29.data[i][j] - bmats.A_9_30.data[i][j] - bmats.Ax2003.data[i][j] - bmats.Ax2801.data[i][j] - bmats.Ax423.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_25.data[i][j] + bmats.B_29_16.data[i][j] + bmats.B_9_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_25.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
