#include "fm_7856.h"

inline int fm_7856(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_23_31.data[i][j] - bmats.A_23_32.data[i][j] + 16*bmats.A_26_23.data[i][j] - bmats.A_26_24.data[i][j] - bmats.A_31_25.data[i][j] + 16*bmats.A_31_26.data[i][j] - bmats.Ax2948.data[i][j] - bmats.Ax50.data[i][j] - bmats.Ax618.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_23_31.data[i][j] + bmats.B_26_23.data[i][j] + bmats.B_31_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
