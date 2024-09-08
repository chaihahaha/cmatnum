#include "fm_1663.h"

inline int fm_1663(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_31.data[i][j] - bmats.A_18_32.data[i][j] + bmats.A_20_1.data[i][j] + bmats.A_20_10.data[i][j] + bmats.A_20_11.data[i][j] + bmats.A_20_12.data[i][j] + bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] + bmats.A_20_15.data[i][j] + bmats.A_20_16.data[i][j] - 16*bmats.A_20_2.data[i][j] + bmats.A_20_3.data[i][j] + bmats.A_20_4.data[i][j] + bmats.A_20_5.data[i][j] + bmats.A_20_6.data[i][j] + bmats.A_20_7.data[i][j] + bmats.A_20_8.data[i][j] + bmats.A_20_9.data[i][j] - bmats.Ax4329.data[i][j] - bmats.Ax600.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] + bmats.B_20_18.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_2_18.data[i][j] - bmats.B_2_19.data[i][j] - bmats.B_2_20.data[i][j] - bmats.B_2_21.data[i][j] - bmats.B_2_22.data[i][j] - bmats.B_2_23.data[i][j] - bmats.B_2_24.data[i][j] - bmats.B_2_25.data[i][j] - bmats.B_2_26.data[i][j] - bmats.B_2_27.data[i][j] - bmats.B_2_28.data[i][j] - bmats.B_2_29.data[i][j] - bmats.B_2_30.data[i][j] - bmats.B_2_31.data[i][j] - bmats.B_2_32.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_32_4.data[i][j] - bmats.Bx11923.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_4.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
