#include "fm_14872.h"

inline int fm_14872(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_15.data[i][j] + 16*bmats.A_12_16.data[i][j] - bmats.A_16_15.data[i][j] + 16*bmats.A_16_16.data[i][j] - bmats.A_2_31.data[i][j] - bmats.A_2_32.data[i][j] - bmats.A_32_1.data[i][j] + 16*bmats.A_32_2.data[i][j] - bmats.Ax463.data[i][j] - bmats.Ax4670.data[i][j] - bmats.Ax565.data[i][j] - bmats.Ax7791.data[i][j] - bmats.Ax789.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_18.data[i][j] - bmats.B_2_1.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_2_16.data[i][j] - bmats.B_2_2.data[i][j] - bmats.B_2_3.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_2_8.data[i][j] - bmats.B_2_9.data[i][j] - bmats.B_31_16.data[i][j] - bmats.B_32_16.data[i][j] - bmats.Bx13360.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
