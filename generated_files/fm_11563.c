#include "fm_11563.h"

inline int fm_11563(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_24_5.data[i][j] - bmats.A_24_6.data[i][j] - bmats.Ax3535.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_24_21.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_8.data[i][j]+=17 * m.data[i][j];
        bmats.C_24_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}