#include "fm_7815.h"

inline int fm_7815(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_23_31.data[i][j] - bmats.A_23_32.data[i][j] + 16*bmats.A_29_23.data[i][j] - bmats.A_29_24.data[i][j] + 16*bmats.A_31_29.data[i][j] - bmats.A_31_30.data[i][j] - bmats.Ax1079.data[i][j] - bmats.Ax2031.data[i][j] - bmats.Ax618.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_23_31.data[i][j] + bmats.B_29_23.data[i][j] + bmats.B_31_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
