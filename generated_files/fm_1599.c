#include "fm_1599.h"

inline int fm_1599(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_20_23.data[i][j] - 17*bmats.A_23_20.data[i][j] + bmats.A_28_19.data[i][j] - 16*bmats.A_28_20.data[i][j] + bmats.Ax161.data[i][j] + bmats.Ax4420.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_20.data[i][j] - bmats.B_18_20.data[i][j] - bmats.B_19_20.data[i][j] + bmats.B_20_23.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_23_17.data[i][j] - bmats.B_23_18.data[i][j] - bmats.B_23_19.data[i][j] - 2*bmats.B_23_20.data[i][j] - bmats.B_23_21.data[i][j] - bmats.B_23_22.data[i][j] - bmats.B_23_23.data[i][j] - bmats.B_23_24.data[i][j] - bmats.B_23_25.data[i][j] - bmats.B_23_26.data[i][j] - bmats.B_23_27.data[i][j] - bmats.B_23_28.data[i][j] - bmats.B_23_29.data[i][j] - bmats.B_23_30.data[i][j] - bmats.B_23_31.data[i][j] - bmats.B_23_32.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_29_20.data[i][j] - bmats.B_31_20.data[i][j] - bmats.B_32_20.data[i][j] - bmats.Bx11895.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}