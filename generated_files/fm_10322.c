#include "fm_10322.h"

inline int fm_10322(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_11.data[i][j] + 16*bmats.A_16_12.data[i][j] - bmats.Ax2184.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_32_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_16.data[i][j]+=17 * m.data[i][j];
        bmats.C_16_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
