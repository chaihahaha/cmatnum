#include "fm_753.h"

inline int fm_753(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_11.data[i][j] - bmats.A_11_12.data[i][j] - bmats.A_27_1.data[i][j] + 16*bmats.A_27_2.data[i][j] - bmats.A_2_31.data[i][j] - bmats.A_2_32.data[i][j] + 16*bmats.A_3_11.data[i][j] - bmats.A_3_12.data[i][j] - bmats.Ax2190.data[i][j] - bmats.Ax2208.data[i][j] - bmats.Ax2558.data[i][j] - bmats.Ax2882.data[i][j] - bmats.Ax789.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_18.data[i][j] - bmats.B_17_11.data[i][j] - bmats.B_18_11.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_20_11.data[i][j] - bmats.B_21_11.data[i][j] - bmats.B_22_11.data[i][j] - bmats.B_23_11.data[i][j] - bmats.B_24_11.data[i][j] - bmats.B_25_11.data[i][j] - bmats.B_26_11.data[i][j] - bmats.B_27_11.data[i][j] - bmats.B_28_11.data[i][j] - bmats.B_29_11.data[i][j] - bmats.B_2_1.data[i][j] - bmats.B_2_10.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_2_16.data[i][j] - bmats.B_2_2.data[i][j] - bmats.B_2_3.data[i][j] - bmats.B_2_4.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_2_7.data[i][j] - bmats.B_2_8.data[i][j] - bmats.B_2_9.data[i][j] - bmats.B_30_11.data[i][j] - bmats.B_31_11.data[i][j] - bmats.B_32_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
