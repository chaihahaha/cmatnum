#include "fm_14856.h"

inline int fm_14856(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_15_15.data[i][j] - bmats.A_15_16.data[i][j] + 16*bmats.A_16_15.data[i][j] - bmats.A_16_16.data[i][j] - bmats.A_16_31.data[i][j] - bmats.A_16_32.data[i][j] - bmats.A_31_15.data[i][j] + 16*bmats.A_31_16.data[i][j] - bmats.Ax463.data[i][j] - bmats.Ax649.data[i][j] - bmats.Ax654.data[i][j] - bmats.Ax679.data[i][j] - bmats.Ax751.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_32.data[i][j] - bmats.B_16_1.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_16_11.data[i][j] - bmats.B_16_12.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_16_16.data[i][j] - bmats.B_16_2.data[i][j] - bmats.B_16_3.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_16_6.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_16_8.data[i][j] - bmats.B_16_9.data[i][j] - bmats.Bx13385.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}