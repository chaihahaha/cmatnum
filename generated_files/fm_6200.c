#include "fm_6200.h"

inline int fm_6200(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_27.data[i][j] + 16*bmats.A_13_28.data[i][j] - bmats.A_28_15.data[i][j] + 16*bmats.A_28_16.data[i][j] + bmats.A_32_19.data[i][j] + bmats.A_32_28.data[i][j] - 16*bmats.A_32_29.data[i][j] + bmats.A_32_32.data[i][j] - bmats.Ax1963.data[i][j] - bmats.Ax5992.data[i][j] - bmats.Ax688.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_29.data[i][j] + bmats.B_28_32.data[i][j] + bmats.B_29_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
