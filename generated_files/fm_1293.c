#include "fm_1293.h"

inline int fm_1293(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_22_10.data[i][j] - 16*bmats.A_22_15.data[i][j] - bmats.A_31_31.data[i][j] - bmats.A_31_32.data[i][j] - bmats.Ax3993.data[i][j] - bmats.Ax664.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_17.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_15_20.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_15_25.data[i][j] - bmats.B_15_26.data[i][j] - bmats.B_15_27.data[i][j] - bmats.B_15_28.data[i][j] - bmats.B_15_29.data[i][j] - bmats.B_15_30.data[i][j] - bmats.B_15_31.data[i][j] - bmats.B_15_32.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] + bmats.B_22_31.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_32_6.data[i][j] - bmats.Bx10674.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}