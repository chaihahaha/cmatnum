#include "fm_599.h"

inline int fm_599(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_28_19.data[i][j] + bmats.A_28_20.data[i][j] - bmats.A_3_32.data[i][j] + bmats.Ax161.data[i][j] + bmats.Ax2277.data[i][j] + bmats.Ax941.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_19.data[i][j] - bmats.B_17_28.data[i][j] - bmats.B_18_28.data[i][j] - bmats.B_19_1.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_19_16.data[i][j] - bmats.B_19_2.data[i][j] - bmats.B_19_28.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_28.data[i][j] - bmats.B_21_28.data[i][j] - bmats.B_22_28.data[i][j] - bmats.B_23_28.data[i][j] - bmats.B_24_28.data[i][j] - bmats.B_25_28.data[i][j] - bmats.B_26_28.data[i][j] - bmats.B_27_28.data[i][j] - bmats.B_28_28.data[i][j] - bmats.B_29_28.data[i][j] - bmats.B_30_28.data[i][j] - bmats.B_31_28.data[i][j] - bmats.B_32_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}