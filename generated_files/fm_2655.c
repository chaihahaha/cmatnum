#include "fm_2655.h"

inline int fm_2655(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_12_25.data[i][j] - bmats.A_12_26.data[i][j] - bmats.A_30_11.data[i][j] + 16*bmats.A_30_12.data[i][j] + bmats.A_9_13.data[i][j] - 16*bmats.A_9_14.data[i][j] - bmats.Ax1224.data[i][j] - bmats.Ax2387.data[i][j] - bmats.Ax5073.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_9.data[i][j] + bmats.B_14_28.data[i][j] + bmats.B_25_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
