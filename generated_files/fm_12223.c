#include "fm_12223.h"

inline int fm_12223(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_24_15.data[i][j] - bmats.A_24_16.data[i][j] + bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] - 16*bmats.A_31_21.data[i][j] + bmats.A_31_31.data[i][j] - bmats.A_5_23.data[i][j] + 16*bmats.A_5_24.data[i][j] - bmats.Ax3439.data[i][j] - bmats.Ax697.data[i][j] - bmats.Ax7887.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_21.data[i][j] + bmats.B_21_8.data[i][j] + bmats.B_24_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
