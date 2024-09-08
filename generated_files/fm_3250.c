#include "fm_3250.h"

inline int fm_3250(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_15_21.data[i][j] - bmats.A_15_22.data[i][j] + 16*bmats.A_28_15.data[i][j] - bmats.A_28_16.data[i][j] + bmats.A_5_11.data[i][j] - 16*bmats.A_5_12.data[i][j] - bmats.Ax3847.data[i][j] - bmats.Ax5218.data[i][j] - bmats.Ax688.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_31.data[i][j] + bmats.B_15_5.data[i][j] + bmats.B_21_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_31.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
