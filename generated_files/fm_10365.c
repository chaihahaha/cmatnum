#include "fm_10365.h"

inline int fm_10365(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_13.data[i][j] + 16*bmats.A_13_14.data[i][j] + 16*bmats.A_14_7.data[i][j] - bmats.A_14_8.data[i][j] + 16*bmats.A_7_13.data[i][j] - bmats.A_7_14.data[i][j] - bmats.Ax1027.data[i][j] - bmats.Ax1030.data[i][j] - bmats.Ax1391.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_14.data[i][j] + bmats.B_14_7.data[i][j] + bmats.B_7_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}