#include "fm_5477.h"

inline int fm_5477(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_6_1.data[i][j] - bmats.A_6_10.data[i][j] - bmats.A_6_11.data[i][j] - bmats.A_6_2.data[i][j] - bmats.A_6_3.data[i][j] - bmats.A_6_4.data[i][j] - bmats.A_6_5.data[i][j] - bmats.A_6_6.data[i][j] + 11*bmats.A_6_7.data[i][j] - bmats.A_6_8.data[i][j] - bmats.A_6_9.data[i][j] - bmats.A_7_1.data[i][j] - bmats.A_7_10.data[i][j] - bmats.A_7_11.data[i][j] - bmats.A_7_2.data[i][j] - bmats.A_7_3.data[i][j] - bmats.A_7_4.data[i][j] - bmats.A_7_5.data[i][j] - bmats.A_7_6.data[i][j] - bmats.A_7_7.data[i][j] + 11*bmats.A_7_8.data[i][j] - bmats.A_7_9.data[i][j] - bmats.A_8_1.data[i][j] - bmats.A_8_10.data[i][j] - bmats.A_8_11.data[i][j] - bmats.A_8_2.data[i][j] - bmats.A_8_3.data[i][j] - bmats.A_8_4.data[i][j] - bmats.A_8_5.data[i][j] + 11*bmats.A_8_6.data[i][j] - bmats.A_8_7.data[i][j] - bmats.A_8_8.data[i][j] - bmats.A_8_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_8_6.data[i][j]+bmats.B_6_7.data[i][j]+bmats.B_7_8.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
