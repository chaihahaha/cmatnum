#include "fm_14873.h"

inline int fm_14873(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_17.data[i][j] + 16*bmats.A_16_18.data[i][j] - bmats.A_18_15.data[i][j] - bmats.A_18_16.data[i][j] - bmats.A_28_31.data[i][j] + 16*bmats.A_28_32.data[i][j] - bmats.A_32_31.data[i][j] + 16*bmats.A_32_32.data[i][j] - bmats.Ax4680.data[i][j] - bmats.Ax533.data[i][j] - bmats.Ax612.data[i][j] - bmats.Ax720.data[i][j] - bmats.Ax7795.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_32.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_18_17.data[i][j] - bmats.B_18_18.data[i][j] - bmats.B_18_19.data[i][j] - bmats.B_18_20.data[i][j] - bmats.B_18_21.data[i][j] - bmats.B_18_22.data[i][j] - bmats.B_18_23.data[i][j] - bmats.B_18_24.data[i][j] - bmats.B_18_25.data[i][j] - bmats.B_18_26.data[i][j] - bmats.B_18_27.data[i][j] - bmats.B_18_28.data[i][j] - bmats.B_18_29.data[i][j] - bmats.B_18_30.data[i][j] - bmats.B_18_31.data[i][j] - bmats.B_18_32.data[i][j] + bmats.B_32_2.data[i][j] - bmats.Bx13238.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}