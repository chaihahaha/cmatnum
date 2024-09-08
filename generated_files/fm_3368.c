#include "fm_3368.h"

inline int fm_3368(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_13_11.data[i][j] + bmats.A_13_12.data[i][j] - bmats.A_27_5.data[i][j] + 16*bmats.A_27_6.data[i][j] + 16*bmats.A_6_29.data[i][j] - bmats.A_6_30.data[i][j] - bmats.Ax2780.data[i][j] - bmats.Ax414.data[i][j] - bmats.Ax5172.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_22.data[i][j] + bmats.B_29_11.data[i][j] + bmats.B_6_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
