#include "fm_9870.h"

inline int fm_9870(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_5_15.data[i][j] - 16*bmats.A_5_16.data[i][j] + bmats.Ax591.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_5_16.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_5.data[i][j]+=17 * m.data[i][j];
        bmats.C_5_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_16.data[i][j]+=2 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}