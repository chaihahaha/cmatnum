#include "fm_680.h"

inline int fm_680(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_27.data[i][j] - bmats.A_11_28.data[i][j] + 16*bmats.A_19_27.data[i][j] - bmats.A_19_28.data[i][j] - bmats.A_27_15.data[i][j] - bmats.A_27_16.data[i][j] + 16*bmats.A_27_27.data[i][j] - bmats.A_27_28.data[i][j] - bmats.Ax2230.data[i][j] - bmats.Ax2291.data[i][j] - bmats.Ax2567.data[i][j] - bmats.Ax28.data[i][j] - bmats.Ax685.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_27.data[i][j] - bmats.B_11_27.data[i][j] - bmats.B_12_27.data[i][j] - bmats.B_13_27.data[i][j] - bmats.B_14_27.data[i][j] - bmats.B_15_27.data[i][j] - bmats.B_16_27.data[i][j] - bmats.B_1_27.data[i][j] + bmats.B_27_11.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_27_18.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_27_21.data[i][j] - bmats.B_27_22.data[i][j] - bmats.B_27_23.data[i][j] - bmats.B_27_24.data[i][j] - bmats.B_27_25.data[i][j] - bmats.B_27_26.data[i][j] - bmats.B_27_27.data[i][j] - bmats.B_27_28.data[i][j] - bmats.B_27_29.data[i][j] - bmats.B_27_30.data[i][j] - bmats.B_27_31.data[i][j] - bmats.B_27_32.data[i][j] - bmats.B_2_27.data[i][j] - bmats.B_3_27.data[i][j] - bmats.B_4_27.data[i][j] - bmats.B_5_27.data[i][j] - bmats.B_6_27.data[i][j] - bmats.B_7_27.data[i][j] - bmats.B_8_27.data[i][j] - bmats.B_9_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}