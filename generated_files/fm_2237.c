#include "fm_2237.h"

inline int fm_2237(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_2_19.data[i][j] + 16*bmats.A_2_20.data[i][j] - bmats.A_32_1.data[i][j] + 16*bmats.A_32_2.data[i][j] + bmats.A_4_15.data[i][j] - 16*bmats.A_4_16.data[i][j] - bmats.Ax4318.data[i][j] - bmats.Ax4447.data[i][j] - bmats.Ax4670.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_18.data[i][j] + bmats.B_20_16.data[i][j] + bmats.B_2_4.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}