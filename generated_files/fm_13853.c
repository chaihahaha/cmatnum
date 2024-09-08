#include "fm_13853.h"

inline int fm_13853(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_26_18.data[i][j] + bmats.A_26_20.data[i][j] - 16*bmats.A_26_21.data[i][j] + bmats.A_26_22.data[i][j] + bmats.A_26_26.data[i][j] + bmats.A_26_28.data[i][j] + bmats.A_26_29.data[i][j] + bmats.A_26_30.data[i][j] + 16*bmats.A_31_10.data[i][j] - bmats.A_31_9.data[i][j] + 16*bmats.A_5_31.data[i][j] - bmats.A_5_32.data[i][j] - bmats.Ax2804.data[i][j] - bmats.Ax781.data[i][j] - bmats.Ax8340.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_21.data[i][j] + bmats.B_21_15.data[i][j] + bmats.B_31_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
