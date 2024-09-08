#include "fm_13330.h"

inline int fm_13330(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_16_29.data[i][j] - bmats.A_16_30.data[i][j] - bmats.A_28_31.data[i][j] + 16*bmats.A_28_32.data[i][j] - bmats.A_29_15.data[i][j] - bmats.A_29_16.data[i][j] - bmats.A_32_31.data[i][j] + 16*bmats.A_32_32.data[i][j] - bmats.Ax399.data[i][j] - bmats.Ax533.data[i][j] - bmats.Ax612.data[i][j] - bmats.Ax691.data[i][j] - bmats.Ax7795.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_32.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_29_27.data[i][j] - bmats.B_29_28.data[i][j] - bmats.B_29_29.data[i][j] - bmats.B_29_30.data[i][j] - bmats.B_29_31.data[i][j] - bmats.B_29_32.data[i][j] + bmats.B_32_13.data[i][j] - bmats.Bx13238.data[i][j] - bmats.Bx4622.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
