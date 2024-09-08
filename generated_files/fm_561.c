#include "fm_561.h"

inline int fm_561(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_26_31.data[i][j] - bmats.A_26_32.data[i][j] - 16*bmats.A_28_10.data[i][j] + bmats.A_28_9.data[i][j] - bmats.Ax2393.data[i][j] - bmats.Ax627.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_17.data[i][j] - bmats.B_10_18.data[i][j] - bmats.B_10_19.data[i][j] - bmats.B_10_20.data[i][j] - bmats.B_10_21.data[i][j] - bmats.B_10_22.data[i][j] - bmats.B_10_23.data[i][j] - bmats.B_10_24.data[i][j] - bmats.B_10_25.data[i][j] - bmats.B_10_26.data[i][j] - bmats.B_10_27.data[i][j] - bmats.B_10_28.data[i][j] - bmats.B_10_29.data[i][j] - bmats.B_10_30.data[i][j] - bmats.B_10_31.data[i][j] - bmats.B_10_32.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_28_12.data[i][j] + bmats.B_28_26.data[i][j] - bmats.B_29_12.data[i][j] - bmats.B_30_12.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_32_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
