#include "fm_1435.h"

inline int fm_1435(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_21_29.data[i][j] - 16*bmats.A_28_21.data[i][j] + bmats.A_28_22.data[i][j] - 17*bmats.A_29_21.data[i][j] + bmats.Ax179.data[i][j] + bmats.Ax4209.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_21.data[i][j] - bmats.B_18_21.data[i][j] - bmats.B_19_21.data[i][j] - bmats.B_20_21.data[i][j] - bmats.B_21_21.data[i][j] + bmats.B_21_29.data[i][j] - bmats.B_22_21.data[i][j] - bmats.B_23_21.data[i][j] - bmats.B_24_21.data[i][j] - bmats.B_25_21.data[i][j] - bmats.B_26_21.data[i][j] - bmats.B_27_21.data[i][j] - bmats.B_28_21.data[i][j] - bmats.B_29_17.data[i][j] - bmats.B_29_18.data[i][j] - bmats.B_29_19.data[i][j] - bmats.B_29_20.data[i][j] - 2*bmats.B_29_21.data[i][j] - bmats.B_29_22.data[i][j] - bmats.B_29_23.data[i][j] - bmats.B_29_24.data[i][j] - bmats.B_29_25.data[i][j] - bmats.B_29_26.data[i][j] - bmats.B_29_27.data[i][j] - bmats.B_29_28.data[i][j] - bmats.B_29_29.data[i][j] - bmats.B_29_30.data[i][j] - bmats.B_29_31.data[i][j] - bmats.B_29_32.data[i][j] - bmats.B_30_21.data[i][j] - bmats.B_31_21.data[i][j] - bmats.B_32_21.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}