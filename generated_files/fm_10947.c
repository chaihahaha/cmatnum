#include "fm_10947.h"

inline int fm_10947(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_10.data[i][j] + 16*bmats.A_20_9.data[i][j] - bmats.Ax2828.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_20_25.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_4.data[i][j]+=17 * m.data[i][j];
        bmats.C_20_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}