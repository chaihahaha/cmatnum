#include "fm_3831.h"

inline int fm_3831(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -12*bmats.A_10_11.data[i][j] + 12*bmats.A_11_10.data[i][j] - 12*bmats.A_11_11.data[i][j] + bmats.A_1_1.data[i][j] + bmats.A_1_10.data[i][j] - 11*bmats.A_1_11.data[i][j] + bmats.A_1_2.data[i][j] + bmats.A_1_3.data[i][j] + bmats.A_1_4.data[i][j] + bmats.A_1_5.data[i][j] + bmats.A_1_6.data[i][j] + bmats.A_1_7.data[i][j] + bmats.A_1_8.data[i][j] + bmats.A_1_9.data[i][j] + bmats.A_2_1.data[i][j] + bmats.A_2_10.data[i][j] - 11*bmats.A_2_11.data[i][j] + bmats.A_2_2.data[i][j] + bmats.A_2_3.data[i][j] + bmats.A_2_4.data[i][j] + bmats.A_2_5.data[i][j] + bmats.A_2_6.data[i][j] + bmats.A_2_7.data[i][j] + bmats.A_2_8.data[i][j] + bmats.A_2_9.data[i][j] + bmats.A_3_1.data[i][j] + bmats.A_3_10.data[i][j] - 11*bmats.A_3_11.data[i][j] + bmats.A_3_2.data[i][j] + bmats.A_3_3.data[i][j] + bmats.A_3_4.data[i][j] + bmats.A_3_5.data[i][j] + bmats.A_3_6.data[i][j] + bmats.A_3_7.data[i][j] + bmats.A_3_8.data[i][j] + bmats.A_3_9.data[i][j] + bmats.A_4_1.data[i][j] + bmats.A_4_10.data[i][j] - 11*bmats.A_4_11.data[i][j] + bmats.A_4_2.data[i][j] + bmats.A_4_3.data[i][j] + bmats.A_4_4.data[i][j] + bmats.A_4_5.data[i][j] + bmats.A_4_6.data[i][j] + bmats.A_4_7.data[i][j] + bmats.A_4_8.data[i][j] + bmats.A_4_9.data[i][j] + bmats.A_5_1.data[i][j] + bmats.A_5_10.data[i][j] - 11*bmats.A_5_11.data[i][j] + bmats.A_5_2.data[i][j] + bmats.A_5_3.data[i][j] + bmats.A_5_4.data[i][j] + bmats.A_5_5.data[i][j] + bmats.A_5_6.data[i][j] + bmats.A_5_7.data[i][j] + bmats.A_5_8.data[i][j] + bmats.A_5_9.data[i][j] + bmats.A_6_1.data[i][j] + bmats.A_6_10.data[i][j] - 11*bmats.A_6_11.data[i][j] + bmats.A_6_2.data[i][j] + bmats.A_6_3.data[i][j] + bmats.A_6_4.data[i][j] + bmats.A_6_5.data[i][j] + bmats.A_6_6.data[i][j] + bmats.A_6_7.data[i][j] + bmats.A_6_8.data[i][j] + bmats.A_6_9.data[i][j] + bmats.A_7_1.data[i][j] + bmats.A_7_10.data[i][j] - 11*bmats.A_7_11.data[i][j] + bmats.A_7_2.data[i][j] + bmats.A_7_3.data[i][j] + bmats.A_7_4.data[i][j] + bmats.A_7_5.data[i][j] + bmats.A_7_6.data[i][j] + bmats.A_7_7.data[i][j] + bmats.A_7_8.data[i][j] + bmats.A_7_9.data[i][j] + bmats.A_8_1.data[i][j] + bmats.A_8_10.data[i][j] - 11*bmats.A_8_11.data[i][j] + bmats.A_8_2.data[i][j] + bmats.A_8_3.data[i][j] + bmats.A_8_4.data[i][j] + bmats.A_8_5.data[i][j] + bmats.A_8_6.data[i][j] + bmats.A_8_7.data[i][j] + bmats.A_8_8.data[i][j] + bmats.A_8_9.data[i][j] + bmats.A_9_1.data[i][j] + bmats.A_9_10.data[i][j] - 11*bmats.A_9_11.data[i][j] + bmats.A_9_2.data[i][j] + bmats.A_9_3.data[i][j] + bmats.A_9_4.data[i][j] + bmats.A_9_5.data[i][j] + bmats.A_9_6.data[i][j] + bmats.A_9_7.data[i][j] + bmats.A_9_8.data[i][j] + bmats.A_9_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_1.data[i][j]-bmats.B_10_2.data[i][j]-bmats.B_10_3.data[i][j]-bmats.B_10_4.data[i][j]-bmats.B_10_5.data[i][j]-bmats.B_10_6.data[i][j]-bmats.B_10_7.data[i][j]-bmats.B_10_8.data[i][j]-bmats.B_10_9.data[i][j]-bmats.B_10_10.data[i][j]+bmats.B_11_10.data[i][j]-bmats.B_1_11.data[i][j]-bmats.B_2_11.data[i][j]-bmats.B_3_11.data[i][j]-bmats.B_4_11.data[i][j]-bmats.B_5_11.data[i][j]-bmats.B_6_11.data[i][j]-bmats.B_7_11.data[i][j]-bmats.B_8_11.data[i][j]-bmats.B_9_11.data[i][j]-2*bmats.B_10_11.data[i][j]-bmats.B_11_11.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
