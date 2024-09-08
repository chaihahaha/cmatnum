#include "fm_3718.h"

inline int fm_3718(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_15_23.data[i][j] - bmats.A_15_24.data[i][j] + 16*bmats.A_26_15.data[i][j] - bmats.A_26_16.data[i][j] - 16*bmats.A_7_10.data[i][j] + bmats.A_7_9.data[i][j] - bmats.Ax3421.data[i][j] - bmats.Ax5342.data[i][j] - bmats.Ax703.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_31.data[i][j] + bmats.B_15_7.data[i][j] + bmats.B_23_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_31.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
