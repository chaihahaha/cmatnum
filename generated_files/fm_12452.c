#include "fm_12452.h"

inline int fm_12452(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_23.data[i][j] + 16*bmats.A_12_24.data[i][j] - bmats.A_24_13.data[i][j] + 16*bmats.A_24_14.data[i][j] + bmats.A_30_18.data[i][j] + bmats.A_30_20.data[i][j] + bmats.A_30_27.data[i][j] - 16*bmats.A_30_28.data[i][j] + bmats.A_30_29.data[i][j] + bmats.A_30_30.data[i][j] + bmats.A_30_31.data[i][j] + bmats.A_30_32.data[i][j] - bmats.Ax2457.data[i][j] - bmats.Ax503.data[i][j] - bmats.Ax8025.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_28.data[i][j] + bmats.B_24_30.data[i][j] + bmats.B_28_8.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}