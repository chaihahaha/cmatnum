#include "fm_11322.h"

inline int fm_11322(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_23_5.data[i][j] - 16*bmats.A_23_6.data[i][j] + bmats.Ax3822.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_7_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_23_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_7.data[i][j]+=17 * m.data[i][j];
        bmats.C_23_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_16.data[i][j]+=1 * m.data[i][j];
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