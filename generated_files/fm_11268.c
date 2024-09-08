#include "fm_11268.h"

inline int fm_11268(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_30_5.data[i][j] + 16*bmats.A_30_6.data[i][j] - bmats.Ax1625.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_30_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_14.data[i][j]+=17 * m.data[i][j];
        bmats.C_30_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_21.data[i][j]+=-1 * m.data[i][j];
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
        bmats.C_30_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
