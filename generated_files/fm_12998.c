#include "fm_12998.h"

inline int fm_12998(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_29.data[i][j] - bmats.A_10_30.data[i][j] + bmats.A_28_25.data[i][j] - 16*bmats.A_28_26.data[i][j] + bmats.A_28_28.data[i][j] + bmats.A_28_30.data[i][j] + bmats.A_28_31.data[i][j] + bmats.A_28_32.data[i][j] - bmats.A_29_11.data[i][j] + 16*bmats.A_29_12.data[i][j] - bmats.Ax1981.data[i][j] - bmats.Ax426.data[i][j] - bmats.Ax7455.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_26.data[i][j] + bmats.B_26_13.data[i][j] + bmats.B_29_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
