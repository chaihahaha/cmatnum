#include "fm_4966.h"

inline int fm_4966(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_10.data[i][j] - 16*bmats.A_10_5.data[i][j] + bmats.A_10_6.data[i][j] - bmats.A_13_25.data[i][j] + 16*bmats.A_13_26.data[i][j] + 16*bmats.A_21_13.data[i][j] - bmats.A_21_14.data[i][j] - bmats.Ax2047.data[i][j] - bmats.Ax521.data[i][j] - bmats.Ax5584.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_10.data[i][j] + bmats.B_26_5.data[i][j] + bmats.B_5_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_29.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}