#include "fm_5597.h"

inline int fm_5597(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_5.data[i][j] + 16*bmats.A_19_6.data[i][j] - 16*bmats.A_2_3.data[i][j] + bmats.A_2_4.data[i][j] - bmats.A_6_17.data[i][j] + 16*bmats.A_6_18.data[i][j] - bmats.Ax3982.data[i][j] - bmats.Ax4084.data[i][j] - bmats.Ax5766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_3.data[i][j] + bmats.B_3_22.data[i][j] + bmats.B_6_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_22.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}