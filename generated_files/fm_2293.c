#include "fm_2293.h"

inline int fm_2293(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_31.data[i][j] + 16*bmats.A_12_32.data[i][j] - 16*bmats.A_16_15.data[i][j] + bmats.A_16_16.data[i][j] - bmats.A_31_11.data[i][j] + 16*bmats.A_31_12.data[i][j] - bmats.Ax2236.data[i][j] - bmats.Ax4855.data[i][j] - bmats.Ax757.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_16.data[i][j] + bmats.B_15_28.data[i][j] + bmats.B_32_15.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
