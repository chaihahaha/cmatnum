#include "fm_5903.h"

inline int fm_5903(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_29.data[i][j] + 16*bmats.A_12_30.data[i][j] - 16*bmats.A_14_1.data[i][j] + bmats.A_14_14.data[i][j] + bmats.A_14_2.data[i][j] - bmats.A_17_11.data[i][j] + 16*bmats.A_17_12.data[i][j] - bmats.Ax2266.data[i][j] - bmats.Ax405.data[i][j] - bmats.Ax5833.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_14.data[i][j] + bmats.B_1_28.data[i][j] + bmats.B_30_1.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}