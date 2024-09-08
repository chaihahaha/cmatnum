#include "fm_6486.h"

inline int fm_6486(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_1_23.data[i][j] - bmats.A_1_24.data[i][j] - 16*bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_20.data[i][j] + bmats.A_20_28.data[i][j] + bmats.A_20_29.data[i][j] + bmats.A_20_30.data[i][j] - bmats.A_23_3.data[i][j] + 16*bmats.A_23_4.data[i][j] - bmats.Ax3445.data[i][j] - bmats.Ax3807.data[i][j] - bmats.Ax6132.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_7.data[i][j] + bmats.B_23_20.data[i][j] + bmats.B_4_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
