#include "fm_1128.h"

inline int fm_1128(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_21_31.data[i][j] - bmats.A_21_32.data[i][j] + bmats.A_24_1.data[i][j] - 16*bmats.A_24_5.data[i][j] - bmats.Ax3628.data[i][j] - bmats.Ax636.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_8.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_22_8.data[i][j] - bmats.B_23_8.data[i][j] + bmats.B_24_21.data[i][j] - bmats.B_24_8.data[i][j] - bmats.B_25_8.data[i][j] - bmats.B_26_8.data[i][j] - bmats.B_27_8.data[i][j] - bmats.B_28_8.data[i][j] - bmats.B_29_8.data[i][j] - bmats.B_30_8.data[i][j] - bmats.B_31_8.data[i][j] - bmats.B_32_8.data[i][j] - bmats.B_5_17.data[i][j] - bmats.B_5_18.data[i][j] - bmats.B_5_19.data[i][j] - bmats.B_5_20.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_5_22.data[i][j] - bmats.B_5_23.data[i][j] - bmats.B_5_24.data[i][j] - bmats.B_5_25.data[i][j] - bmats.B_5_26.data[i][j] - bmats.B_5_27.data[i][j] - bmats.B_5_28.data[i][j] - bmats.B_5_29.data[i][j] - bmats.B_5_30.data[i][j] - bmats.B_5_31.data[i][j] - bmats.B_5_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_8.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}