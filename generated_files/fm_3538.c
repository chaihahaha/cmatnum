#include "fm_3538.h"

inline int fm_3538(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_27_7.data[i][j] - bmats.A_27_8.data[i][j] - 16*bmats.A_3_11.data[i][j] + bmats.A_3_12.data[i][j] + 16*bmats.A_7_19.data[i][j] - bmats.A_7_20.data[i][j] - bmats.Ax2726.data[i][j] - bmats.Ax3810.data[i][j] - bmats.Ax5229.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_23.data[i][j] + bmats.B_19_11.data[i][j] + bmats.B_7_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
