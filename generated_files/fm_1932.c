#include "fm_1932.h"

inline int fm_1932(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_14.data[i][j] - 16*bmats.A_2_1.data[i][j] + bmats.A_2_2.data[i][j] + bmats.Ax4659.data[i][j] + bmats.Ax4688.data[i][j] + bmats.Ax808.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_2.data[i][j] - bmats.B_15_2.data[i][j] - bmats.B_16_2.data[i][j] + bmats.B_18_1.data[i][j] - bmats.B_1_17.data[i][j] - bmats.B_1_18.data[i][j] - bmats.B_1_19.data[i][j] - bmats.B_1_2.data[i][j] - bmats.B_1_20.data[i][j] - bmats.B_1_21.data[i][j] - bmats.B_1_22.data[i][j] - bmats.B_1_23.data[i][j] - bmats.B_1_24.data[i][j] - bmats.B_1_25.data[i][j] - bmats.B_1_26.data[i][j] - bmats.B_1_27.data[i][j] - bmats.B_1_28.data[i][j] - bmats.B_1_29.data[i][j] - bmats.B_1_30.data[i][j] - bmats.B_1_31.data[i][j] - bmats.B_1_32.data[i][j] - bmats.B_3_2.data[i][j] - bmats.B_4_2.data[i][j] - bmats.B_6_2.data[i][j] - bmats.B_7_2.data[i][j] - bmats.Bx12700.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
