#include "fm_613.h"

inline int fm_613(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_11.data[i][j] + 16*bmats.A_12_12.data[i][j] + 16*bmats.A_28_5.data[i][j] - bmats.A_28_6.data[i][j] - bmats.A_2_11.data[i][j] + 16*bmats.A_2_12.data[i][j] - bmats.A_5_31.data[i][j] - bmats.A_5_32.data[i][j] - bmats.Ax2175.data[i][j] - bmats.Ax2178.data[i][j] - bmats.Ax2216.data[i][j] - bmats.Ax2439.data[i][j] - bmats.Ax781.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_21.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_18_12.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_20_12.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_23_12.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_25_12.data[i][j] - bmats.B_26_12.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_28_12.data[i][j] - bmats.B_29_12.data[i][j] - bmats.B_30_12.data[i][j] - bmats.B_31_12.data[i][j] - bmats.B_32_12.data[i][j] - bmats.B_5_1.data[i][j] - bmats.B_5_10.data[i][j] - bmats.B_5_11.data[i][j] - bmats.B_5_12.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_5_16.data[i][j] - bmats.B_5_2.data[i][j] - bmats.B_5_3.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_5_6.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_5_8.data[i][j] - bmats.B_5_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_12.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}