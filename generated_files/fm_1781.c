#include "fm_1781.h"

inline int fm_1781(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_19_3.data[i][j] - bmats.A_19_4.data[i][j] + 16*bmats.A_3_3.data[i][j] - bmats.A_3_31.data[i][j] - bmats.A_3_32.data[i][j] - bmats.A_3_4.data[i][j] + 16*bmats.A_4_3.data[i][j] - bmats.A_4_4.data[i][j] - bmats.Ax4303.data[i][j] - bmats.Ax4339.data[i][j] - bmats.Ax4363.data[i][j] - bmats.Ax4482.data[i][j] - bmats.Ax775.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_3.data[i][j] - bmats.B_18_3.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_32_3.data[i][j] - bmats.B_3_1.data[i][j] - bmats.B_3_10.data[i][j] - bmats.B_3_11.data[i][j] - bmats.B_3_12.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_3_15.data[i][j] - bmats.B_3_16.data[i][j] + bmats.B_3_19.data[i][j] - bmats.B_3_2.data[i][j] - bmats.B_3_3.data[i][j] - bmats.B_3_4.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_3_6.data[i][j] - bmats.B_3_7.data[i][j] - bmats.B_3_8.data[i][j] - bmats.B_3_9.data[i][j] - bmats.Bx12263.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}