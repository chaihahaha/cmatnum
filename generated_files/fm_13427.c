#include "fm_13427.h"

inline int fm_13427(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_23_11.data[i][j] + 16*bmats.A_23_12.data[i][j] - 16*bmats.A_28_23.data[i][j] + bmats.A_28_24.data[i][j] + bmats.A_28_28.data[i][j] + bmats.A_28_30.data[i][j] + bmats.A_28_31.data[i][j] + bmats.A_28_32.data[i][j] + 16*bmats.A_7_23.data[i][j] - bmats.A_7_24.data[i][j] - bmats.Ax2260.data[i][j] - bmats.Ax3427.data[i][j] - bmats.Ax7451.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_23.data[i][j] + bmats.B_23_28.data[i][j] + bmats.B_23_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
