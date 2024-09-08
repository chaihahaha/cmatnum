#include "fm_524.h"

inline int fm_524(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_27.data[i][j] + 16*bmats.A_12_28.data[i][j] - bmats.A_18_27.data[i][j] + 16*bmats.A_18_28.data[i][j] - bmats.A_28_15.data[i][j] - bmats.A_28_16.data[i][j] - bmats.A_28_27.data[i][j] + 16*bmats.A_28_28.data[i][j] - bmats.Ax2232.data[i][j] - bmats.Ax2294.data[i][j] - bmats.Ax23.data[i][j] - bmats.Ax61.data[i][j] - bmats.Ax688.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_28.data[i][j] - bmats.B_11_28.data[i][j] - bmats.B_12_28.data[i][j] - bmats.B_13_28.data[i][j] - bmats.B_14_28.data[i][j] - bmats.B_15_28.data[i][j] - bmats.B_16_28.data[i][j] - bmats.B_1_28.data[i][j] + bmats.B_28_12.data[i][j] - bmats.B_28_17.data[i][j] - bmats.B_28_18.data[i][j] - bmats.B_28_19.data[i][j] - bmats.B_28_20.data[i][j] - bmats.B_28_21.data[i][j] - bmats.B_28_22.data[i][j] - bmats.B_28_23.data[i][j] - bmats.B_28_24.data[i][j] - bmats.B_28_25.data[i][j] - bmats.B_28_26.data[i][j] - bmats.B_28_27.data[i][j] - bmats.B_28_28.data[i][j] - bmats.B_28_29.data[i][j] - bmats.B_28_30.data[i][j] - bmats.B_28_31.data[i][j] - bmats.B_28_32.data[i][j] - bmats.B_2_28.data[i][j] - bmats.B_3_28.data[i][j] - bmats.B_4_28.data[i][j] - bmats.B_5_28.data[i][j] - bmats.B_6_28.data[i][j] - bmats.B_7_28.data[i][j] - bmats.B_8_28.data[i][j] - bmats.B_9_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
