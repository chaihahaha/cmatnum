#include "fm_1519.h"

inline int fm_1519(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_18_21.data[i][j] - bmats.A_18_22.data[i][j] - bmats.A_21_15.data[i][j] - bmats.A_21_16.data[i][j] + 16*bmats.A_21_21.data[i][j] - bmats.A_21_22.data[i][j] + 16*bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j] - bmats.Ax3850.data[i][j] - bmats.Ax3937.data[i][j] - bmats.Ax3943.data[i][j] - bmats.Ax4181.data[i][j] - bmats.Ax712.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_21.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_21_21.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_21_24.data[i][j] - bmats.B_21_25.data[i][j] - bmats.B_21_26.data[i][j] - bmats.B_21_27.data[i][j] - bmats.B_21_28.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_21_30.data[i][j] - bmats.B_21_31.data[i][j] - bmats.B_21_32.data[i][j] + bmats.B_21_5.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_4_21.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx11440.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}