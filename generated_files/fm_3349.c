#include "fm_3349.h"

inline int fm_3349(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_14_11.data[i][j] + bmats.A_14_12.data[i][j] + bmats.A_14_14.data[i][j] - bmats.A_27_7.data[i][j] + 16*bmats.A_27_8.data[i][j] - bmats.A_8_29.data[i][j] + 16*bmats.A_8_30.data[i][j] - bmats.Ax2726.data[i][j] - bmats.Ax420.data[i][j] - bmats.Ax5167.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_24.data[i][j] + bmats.B_30_11.data[i][j] + bmats.B_8_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_24.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}