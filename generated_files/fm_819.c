#include "fm_819.h"

inline int fm_819(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_10.data[i][j] - bmats.A_10_9.data[i][j] + 16*bmats.A_1_10.data[i][j] - bmats.A_1_9.data[i][j] - bmats.A_26_7.data[i][j] + 16*bmats.A_26_8.data[i][j] - bmats.A_8_31.data[i][j] - bmats.A_8_32.data[i][j] - bmats.Ax2941.data[i][j] - bmats.Ax2956.data[i][j] - bmats.Ax2958.data[i][j] - bmats.Ax3002.data[i][j] - bmats.Ax766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_24.data[i][j] - bmats.B_17_10.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_22_10.data[i][j] - bmats.B_23_10.data[i][j] - bmats.B_24_10.data[i][j] - bmats.B_25_10.data[i][j] - bmats.B_26_10.data[i][j] - bmats.B_27_10.data[i][j] - bmats.B_28_10.data[i][j] - bmats.B_29_10.data[i][j] - bmats.B_30_10.data[i][j] - bmats.B_31_10.data[i][j] - bmats.B_32_10.data[i][j] - bmats.B_8_1.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_8_3.data[i][j] - bmats.B_8_4.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_8_6.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_8_8.data[i][j] - bmats.B_8_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
