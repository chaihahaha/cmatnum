#include "fm_10316.h"

inline int fm_10316(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_31_11.data[i][j] + 16*bmats.A_31_12.data[i][j] - bmats.Ax2236.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_31_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_15.data[i][j]+=17 * m.data[i][j];
        bmats.C_31_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}