#include "fm_231.h"

inline int fm_231(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_15_8.data[i][j] - bmats.A_15_9.data[i][j] + 11*bmats.A_4_4.data[i][j] - bmats.A_4_5.data[i][j] - bmats.A_8_21.data[i][j] - bmats.A_8_22.data[i][j] - bmats.Ax1209.data[i][j] - bmats.Ax1276.data[i][j] - bmats.Ax658.data[i][j] - bmats.Ax897.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_4.data[i][j] - bmats.B_13_4.data[i][j] - bmats.B_14_4.data[i][j] - bmats.B_15_4.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_21_4.data[i][j] - bmats.B_22_4.data[i][j] + bmats.B_4_19.data[i][j] - bmats.B_8_1.data[i][j] - bmats.B_8_10.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_8_2.data[i][j] - bmats.B_8_3.data[i][j] - bmats.B_8_4.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_8_6.data[i][j] - bmats.B_8_7.data[i][j] - bmats.B_8_8.data[i][j] - bmats.B_8_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_8.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
