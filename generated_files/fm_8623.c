#include "fm_8623.h"

inline int fm_8623(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_23_18.data[i][j] + bmats.A_23_19.data[i][j] + bmats.A_23_23.data[i][j] + 16*bmats.A_24_7.data[i][j] - bmats.A_24_8.data[i][j] - bmats.A_2_23.data[i][j] + 16*bmats.A_2_24.data[i][j] - bmats.Ax3399.data[i][j] - bmats.Ax3448.data[i][j] - bmats.Ax7027.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_8.data[i][j] + bmats.B_24_23.data[i][j] + bmats.B_7_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_23.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}