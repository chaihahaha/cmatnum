#include "fm_13217.h"

inline int fm_13217(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_28_1.data[i][j] + bmats.A_28_2.data[i][j] + bmats.Ax2633.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_12.data[i][j]+=17 * m.data[i][j];
        bmats.C_28_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_17.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
