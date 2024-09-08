#include "fm_1285.h"

inline int fm_1285(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_22_13.data[i][j] - 16*bmats.A_22_14.data[i][j] - bmats.A_30_31.data[i][j] - bmats.A_30_32.data[i][j] - bmats.Ax3905.data[i][j] - bmats.Ax604.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_17.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] + bmats.B_22_30.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_32_6.data[i][j] - bmats.Bx10674.data[i][j] - bmats.Bx2496.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
