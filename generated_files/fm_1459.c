#include "fm_1459.h"

inline int fm_1459(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_21_26.data[i][j] - 17*bmats.A_26_21.data[i][j] - 16*bmats.A_27_21.data[i][j] + bmats.A_27_22.data[i][j] + bmats.Ax4217.data[i][j] + bmats.Ax74.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_21.data[i][j] - bmats.B_18_21.data[i][j] - bmats.B_19_21.data[i][j] - bmats.B_20_21.data[i][j] + bmats.B_21_26.data[i][j] - bmats.B_22_21.data[i][j] - bmats.B_26_17.data[i][j] - bmats.B_26_18.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_26_20.data[i][j] - 2*bmats.B_26_21.data[i][j] - bmats.B_26_22.data[i][j] - bmats.B_27_21.data[i][j] - bmats.B_31_21.data[i][j] - bmats.B_32_21.data[i][j] - bmats.Bx11658.data[i][j] - bmats.Bx7697.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
