#include "fm_11765.h"

inline int fm_11765(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_29_3.data[i][j] - bmats.A_29_4.data[i][j] - bmats.Ax2143.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_29_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_13.data[i][j]+=17 * m.data[i][j];
        bmats.C_29_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}