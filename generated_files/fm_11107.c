#include "fm_11107.h"

inline int fm_11107(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_1_7.data[i][j] - 16*bmats.A_1_8.data[i][j] + bmats.Ax3473.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_8.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_1.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_8.data[i][j]+=2 * m.data[i][j];
        bmats.C_2_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}