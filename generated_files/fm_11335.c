#include "fm_11335.h"

inline int fm_11335(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_5.data[i][j] + 16*bmats.A_1_6.data[i][j] - bmats.Ax3917.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_6.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_1.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}