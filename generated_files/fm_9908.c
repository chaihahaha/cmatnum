#include "fm_9908.h"

inline int fm_9908(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_18_15.data[i][j] - 16*bmats.A_18_16.data[i][j] + bmats.Ax720.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_2_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_2.data[i][j]+=17 * m.data[i][j];
        bmats.C_18_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_32.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}