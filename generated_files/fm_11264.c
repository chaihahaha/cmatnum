#include "fm_11264.h"

inline int fm_11264(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_30_5.data[i][j] - 16*bmats.A_30_6.data[i][j] + bmats.Ax1625.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=17 * m.data[i][j];
        bmats.C_30_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_22.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}