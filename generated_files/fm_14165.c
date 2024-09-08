#include "fm_14165.h"

inline int fm_14165(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_25.data[i][j] + 16*bmats.A_20_26.data[i][j] - bmats.A_26_31.data[i][j] + 16*bmats.A_26_32.data[i][j] - bmats.A_32_19.data[i][j] + 16*bmats.A_32_20.data[i][j] - bmats.Ax248.data[i][j] - bmats.Ax4376.data[i][j] - bmats.Ax627.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_26.data[i][j] + bmats.B_26_32.data[i][j] + bmats.B_32_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
