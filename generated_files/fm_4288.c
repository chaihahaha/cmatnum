#include "fm_4288.h"

inline int fm_4288(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_19.data[i][j] + 16*bmats.A_13_20.data[i][j] + 16*bmats.A_24_13.data[i][j] - bmats.A_24_14.data[i][j] + bmats.A_4_7.data[i][j] - 16*bmats.A_4_8.data[i][j] - bmats.Ax2146.data[i][j] - bmats.Ax503.data[i][j] - bmats.Ax5487.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_4.data[i][j] + bmats.B_20_8.data[i][j] + bmats.B_8_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_29.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}