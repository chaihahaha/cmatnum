#include "fm_284.h"

inline int fm_284(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_2_10.data[i][j] - bmats.A_2_11.data[i][j] - 11*bmats.A_4_13.data[i][j] + bmats.A_4_14.data[i][j] - bmats.Ax1413.data[i][j] - bmats.Ax261.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_15.data[i][j] - bmats.B_11_15.data[i][j] - bmats.B_13_1.data[i][j] - bmats.B_13_10.data[i][j] - bmats.B_13_11.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_13_3.data[i][j] - bmats.B_13_4.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_13_6.data[i][j] - bmats.B_13_7.data[i][j] - bmats.B_13_8.data[i][j] - bmats.B_13_9.data[i][j] - bmats.B_1_15.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_3_15.data[i][j] - bmats.B_4_15.data[i][j] + bmats.B_4_2.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_6_15.data[i][j] - bmats.B_7_15.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_9_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
