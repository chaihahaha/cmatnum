#include "fm_5399.h"

inline int fm_5399(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_15_3.data[i][j] + bmats.A_15_4.data[i][j] - bmats.A_19_1.data[i][j] + 16*bmats.A_19_2.data[i][j] + 16*bmats.A_2_31.data[i][j] - bmats.A_2_32.data[i][j] - bmats.Ax4586.data[i][j] - bmats.Ax5691.data[i][j] - bmats.Ax789.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_2_15.data[i][j] + bmats.B_31_3.data[i][j] + bmats.B_3_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}