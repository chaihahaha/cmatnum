#include "fm_6357.h"

inline int fm_6357(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_29.data[i][j] + 16*bmats.A_10_30.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_20.data[i][j] + bmats.A_20_21.data[i][j] + bmats.A_20_23.data[i][j] + bmats.A_20_24.data[i][j] - 16*bmats.A_20_26.data[i][j] + bmats.A_20_28.data[i][j] + bmats.A_20_29.data[i][j] + bmats.A_20_30.data[i][j] + bmats.A_20_32.data[i][j] - bmats.A_30_3.data[i][j] + 16*bmats.A_30_4.data[i][j] - bmats.Ax1781.data[i][j] - bmats.Ax426.data[i][j] - bmats.Ax6155.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_26_14.data[i][j] + bmats.B_30_20.data[i][j] + bmats.B_4_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
