#include "fm_3674.h"

inline int fm_3674(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_11_10.data[i][j] + bmats.A_11_9.data[i][j] + 16*bmats.A_16_27.data[i][j] - bmats.A_16_28.data[i][j] - bmats.A_26_15.data[i][j] + 16*bmats.A_26_16.data[i][j] - bmats.Ax2282.data[i][j] - bmats.Ax5314.data[i][j] - bmats.Ax703.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_32.data[i][j] + bmats.B_16_11.data[i][j] + bmats.B_27_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}