#include "fm_12252.h"

inline int fm_12252(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_21.data[i][j] - bmats.A_13_22.data[i][j] + 16*bmats.A_21_15.data[i][j] - bmats.A_21_16.data[i][j] + bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] + bmats.A_31_28.data[i][j] - 16*bmats.A_31_29.data[i][j] + bmats.A_31_31.data[i][j] - bmats.Ax2080.data[i][j] - bmats.Ax712.data[i][j] - bmats.Ax7901.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_29.data[i][j] + bmats.B_21_31.data[i][j] + bmats.B_29_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}