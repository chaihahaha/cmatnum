#include "fm_2723.h"

inline int fm_2723(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_30_3.data[i][j] - bmats.A_30_4.data[i][j] + 16*bmats.A_3_23.data[i][j] - bmats.A_3_24.data[i][j] + bmats.A_7_13.data[i][j] - 16*bmats.A_7_14.data[i][j] - bmats.Ax1781.data[i][j] - bmats.Ax3433.data[i][j] - bmats.Ax5081.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_19.data[i][j] + bmats.B_23_14.data[i][j] + bmats.B_3_7.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_19.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}