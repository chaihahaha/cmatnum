#include "fm_10636.h"

inline int fm_10636(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_25_11.data[i][j] - bmats.A_25_12.data[i][j] - bmats.Ax2242.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_25_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_9.data[i][j]+=17 * m.data[i][j];
        bmats.C_25_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
