#include "fm_11182.h"

inline int fm_11182(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_20_7.data[i][j] + bmats.A_20_8.data[i][j] + bmats.Ax3405.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_4_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_4.data[i][j]+=17 * m.data[i][j];
        bmats.C_20_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}