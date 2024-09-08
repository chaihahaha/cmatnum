#include "fm_1432.h"

inline int fm_1432(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_15.data[i][j] - bmats.A_12_16.data[i][j] + bmats.A_5_27.data[i][j] - 16*bmats.A_5_28.data[i][j] - bmats.Ax4206.data[i][j] - bmats.Ax565.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_21.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_28_14.data[i][j] - bmats.B_28_15.data[i][j] - bmats.B_28_16.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_4_21.data[i][j] + bmats.B_5_12.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx11440.data[i][j] - bmats.Bx6294.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_12_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
