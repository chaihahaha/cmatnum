#include "fm_13046.h"

inline int fm_13046(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_1.data[i][j] + 16*bmats.A_16_2.data[i][j] - bmats.A_1_15.data[i][j] + 16*bmats.A_1_16.data[i][j] + 16*bmats.A_2_1.data[i][j] - bmats.A_2_2.data[i][j] - bmats.Ax4644.data[i][j] - bmats.Ax4659.data[i][j] - bmats.Ax652.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_2.data[i][j] + bmats.B_1_16.data[i][j] + bmats.B_2_1.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
