#include "fm_13153.h"

inline int fm_13153(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_7_1.data[i][j] + 16*bmats.A_7_2.data[i][j] - bmats.Ax3881.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_23_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_7.data[i][j]+=17 * m.data[i][j];
        bmats.C_7_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}