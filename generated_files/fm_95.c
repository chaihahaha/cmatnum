#include "fm_95.h"

inline int fm_95(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_5_10.data[i][j] - bmats.A_5_11.data[i][j] + bmats.A_6_12.data[i][j] - 11*bmats.A_6_16.data[i][j] - bmats.Ax824.data[i][j] - bmats.Ax827.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_17.data[i][j] - bmats.B_11_17.data[i][j] - bmats.B_16_1.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_16_11.data[i][j] - bmats.B_16_2.data[i][j] - bmats.B_16_3.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_16_6.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_16_8.data[i][j] - bmats.B_16_9.data[i][j] - bmats.B_1_17.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_4_17.data[i][j] - bmats.B_5_17.data[i][j] - bmats.B_6_17.data[i][j] + bmats.B_6_5.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_8_17.data[i][j] - bmats.B_9_17.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
