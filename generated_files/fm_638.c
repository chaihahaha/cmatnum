#include "fm_638.h"

inline int fm_638(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_11.data[i][j] + 16*bmats.A_12_12.data[i][j] - bmats.A_28_1.data[i][j] + 16*bmats.A_28_2.data[i][j] - bmats.A_2_11.data[i][j] + 16*bmats.A_2_12.data[i][j] - bmats.A_2_31.data[i][j] - bmats.A_2_32.data[i][j] - bmats.Ax2175.data[i][j] - bmats.Ax2178.data[i][j] - bmats.Ax2216.data[i][j] - bmats.Ax2633.data[i][j] - bmats.Ax789.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_18.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_29_12.data[i][j] - bmats.B_2_1.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_2_16.data[i][j] - bmats.B_2_2.data[i][j] - bmats.B_2_3.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_2_8.data[i][j] - bmats.B_2_9.data[i][j] - bmats.B_30_12.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_32_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}