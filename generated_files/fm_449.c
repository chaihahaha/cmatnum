#include "fm_449.h"

inline int fm_449(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] + 16*bmats.A_29_5.data[i][j] - bmats.A_29_6.data[i][j] + 16*bmats.A_2_13.data[i][j] - bmats.A_2_14.data[i][j] - bmats.A_5_31.data[i][j] - bmats.A_5_32.data[i][j] - bmats.Ax1027.data[i][j] - bmats.Ax1054.data[i][j] - bmats.Ax1939.data[i][j] - bmats.Ax2077.data[i][j] - bmats.Ax781.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_21.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_23_13.data[i][j] - bmats.B_24_13.data[i][j] - bmats.B_25_13.data[i][j] - bmats.B_26_13.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_29_13.data[i][j] - bmats.B_30_13.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_32_13.data[i][j] - bmats.B_5_1.data[i][j] - bmats.B_5_10.data[i][j] - bmats.B_5_11.data[i][j] - bmats.B_5_12.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_5_16.data[i][j] - bmats.B_5_2.data[i][j] - bmats.B_5_3.data[i][j] - bmats.B_5_4.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_5_6.data[i][j] - bmats.B_5_7.data[i][j] - bmats.B_5_8.data[i][j] - bmats.B_5_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_13.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
