#include "fm_763.h"

inline int fm_763(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_27_19.data[i][j] + bmats.A_27_20.data[i][j] - bmats.A_3_32.data[i][j] + bmats.Ax2598.data[i][j] + bmats.Ax69.data[i][j] + bmats.Ax941.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_19.data[i][j] - bmats.B_17_27.data[i][j] - bmats.B_18_27.data[i][j] - bmats.B_19_1.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_19_12.data[i][j] - bmats.B_19_13.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_19_16.data[i][j] - bmats.B_19_2.data[i][j] - bmats.B_19_27.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_27.data[i][j] - bmats.B_21_27.data[i][j] - bmats.B_22_27.data[i][j] - bmats.B_23_27.data[i][j] - bmats.B_24_27.data[i][j] - bmats.B_25_27.data[i][j] - bmats.B_26_27.data[i][j] - bmats.B_27_27.data[i][j] - bmats.B_28_27.data[i][j] - bmats.B_29_27.data[i][j] - bmats.B_30_27.data[i][j] - bmats.B_31_27.data[i][j] - bmats.B_32_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}