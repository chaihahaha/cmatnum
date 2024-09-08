#include "fm_989.h"

inline int fm_989(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_31.data[i][j] - bmats.A_18_32.data[i][j] - 16*bmats.A_25_2.data[i][j] + bmats.A_25_7.data[i][j] - bmats.Ax3330.data[i][j] - bmats.Ax600.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_9.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_23_9.data[i][j] - bmats.B_24_9.data[i][j] + bmats.B_25_18.data[i][j] - bmats.B_25_9.data[i][j] - bmats.B_26_9.data[i][j] - bmats.B_27_9.data[i][j] - bmats.B_28_9.data[i][j] - bmats.B_29_9.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_2_18.data[i][j] - bmats.B_2_19.data[i][j] - bmats.B_2_20.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_2_22.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_2_24.data[i][j] - bmats.B_2_25.data[i][j] - bmats.B_2_26.data[i][j] - bmats.B_2_27.data[i][j] - bmats.B_2_28.data[i][j] - bmats.B_2_29.data[i][j] - bmats.B_2_30.data[i][j] - bmats.B_2_31.data[i][j] - bmats.B_2_32.data[i][j] - bmats.B_30_9.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_32_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
