#include "fm_152.h"

inline int fm_152(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_11.data[i][j] + bmats.A_5_4.data[i][j] - 11*bmats.A_5_5.data[i][j] + bmats.Ax822.data[i][j] + bmats.Ax876.data[i][j] + bmats.Ax982.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_5.data[i][j] - bmats.B_11_5.data[i][j] + bmats.B_16_5.data[i][j] - bmats.B_1_5.data[i][j] - bmats.B_2_5.data[i][j] - bmats.B_3_5.data[i][j] - bmats.B_4_5.data[i][j] - bmats.B_5_12.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_5_16.data[i][j] - bmats.B_5_17.data[i][j] - bmats.B_5_18.data[i][j] - bmats.B_5_19.data[i][j] - bmats.B_5_20.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_5_22.data[i][j] - bmats.B_5_5.data[i][j] - bmats.B_6_5.data[i][j] - bmats.B_7_5.data[i][j] - bmats.B_8_5.data[i][j] - bmats.B_9_5.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
