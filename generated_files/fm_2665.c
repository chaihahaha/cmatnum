#include "fm_2665.h"

inline int fm_2665(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_10_13.data[i][j] - 16*bmats.A_10_14.data[i][j] - bmats.A_30_5.data[i][j] + 16*bmats.A_30_6.data[i][j] - bmats.A_6_25.data[i][j] + 16*bmats.A_6_26.data[i][j] - bmats.Ax1625.data[i][j] - bmats.Ax2857.data[i][j] - bmats.Ax5065.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_22.data[i][j] + bmats.B_26_14.data[i][j] + bmats.B_6_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_22.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}