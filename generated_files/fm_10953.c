#include "fm_10953.h"

inline int fm_10953(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_5_10.data[i][j] + 16*bmats.A_5_9.data[i][j] - bmats.Ax2938.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_9.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_5.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
