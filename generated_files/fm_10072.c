#include "fm_10072.h"

inline int fm_10072(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_27_13.data[i][j] + 16*bmats.A_27_14.data[i][j] - bmats.Ax488.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_11.data[i][j]+=17 * m.data[i][j];
        bmats.C_27_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
