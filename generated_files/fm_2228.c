#include "fm_2228.h"

inline int fm_2228(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_8.data[i][j] + 11*bmats.A_13_9.data[i][j] + bmats.A_20_15.data[i][j] - 11*bmats.A_20_20.data[i][j] + 11*bmats.A_9_13.data[i][j] - bmats.A_9_14.data[i][j] - bmats.Ax1366.data[i][j] - bmats.Ax1670.data[i][j] - bmats.Ax2705.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_20.data[i][j] + bmats.B_20_2.data[i][j] + bmats.B_9_20.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
