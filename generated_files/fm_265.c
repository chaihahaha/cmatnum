#include "fm_265.h"

inline int fm_265(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_30_14.data[i][j] + bmats.A_30_15.data[i][j] - bmats.A_30_31.data[i][j] - bmats.A_30_32.data[i][j] - bmats.Ax1137.data[i][j] - bmats.Ax604.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_17.data[i][j] - bmats.B_14_18.data[i][j] - bmats.B_14_19.data[i][j] - bmats.B_14_20.data[i][j] - bmats.B_14_21.data[i][j] - bmats.B_14_22.data[i][j] - bmats.B_14_23.data[i][j] - bmats.B_14_24.data[i][j] - bmats.B_14_25.data[i][j] - bmats.B_14_26.data[i][j] - bmats.B_14_27.data[i][j] - bmats.B_14_28.data[i][j] - bmats.B_14_29.data[i][j] - bmats.B_14_30.data[i][j] - bmats.B_14_31.data[i][j] - bmats.B_14_32.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_23_14.data[i][j] - bmats.B_24_14.data[i][j] - bmats.B_25_14.data[i][j] - bmats.B_26_14.data[i][j] - bmats.B_27_14.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_29_14.data[i][j] - bmats.B_30_14.data[i][j] + bmats.B_30_30.data[i][j] - bmats.B_31_14.data[i][j] - bmats.B_32_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}