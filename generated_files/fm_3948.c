#include "fm_3948.h"

inline int fm_3948(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_10.data[i][j] - 16*bmats.A_10_9.data[i][j] - bmats.A_15_25.data[i][j] + 16*bmats.A_15_26.data[i][j] + 16*bmats.A_25_15.data[i][j] - bmats.A_25_16.data[i][j] - bmats.Ax2842.data[i][j] - bmats.Ax5312.data[i][j] - bmats.Ax700.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_10.data[i][j] + bmats.B_26_9.data[i][j] + bmats.B_9_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_31.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
