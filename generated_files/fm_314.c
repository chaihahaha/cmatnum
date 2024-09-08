#include "fm_314.h"

inline int fm_314(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_13.data[i][j] + 11*bmats.A_14_14.data[i][j] - bmats.A_22_10.data[i][j] - bmats.A_22_11.data[i][j] - bmats.A_3_21.data[i][j] + 11*bmats.A_3_22.data[i][j] - bmats.Ax1479.data[i][j] - bmats.Ax1484.data[i][j] - bmats.Ax274.data[i][j] - bmats.Ax567.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_14.data[i][j] - bmats.B_11_14.data[i][j] + bmats.B_14_11.data[i][j] - bmats.B_1_14.data[i][j] - bmats.B_22_12.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_22_14.data[i][j] - bmats.B_22_15.data[i][j] - bmats.B_22_16.data[i][j] - bmats.B_22_17.data[i][j] - bmats.B_22_18.data[i][j] - bmats.B_22_19.data[i][j] - bmats.B_22_20.data[i][j] - bmats.B_22_21.data[i][j] - bmats.B_22_22.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_4_14.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_9_14.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
