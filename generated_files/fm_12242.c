#include "fm_12242.h"

inline int fm_12242(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_23_15.data[i][j] - bmats.A_23_16.data[i][j] + bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] - 16*bmats.A_31_22.data[i][j] + bmats.A_31_23.data[i][j] + bmats.A_31_31.data[i][j] + 16*bmats.A_6_23.data[i][j] - bmats.A_6_24.data[i][j] - bmats.Ax3442.data[i][j] - bmats.Ax694.data[i][j] - bmats.Ax7889.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_22.data[i][j] + bmats.B_22_7.data[i][j] + bmats.B_23_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
