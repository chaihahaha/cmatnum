#include "fm_9795.h"

inline int fm_9795(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] + 16*bmats.A_2_13.data[i][j] - bmats.A_2_14.data[i][j] - bmats.Ax1027.data[i][j] - bmats.Ax1054.data[i][j] - bmats.Ax1939.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.Bx13310.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_13.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
