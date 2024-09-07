#include "fm_3110.h"

inline int fm_3110(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_12.data[i][j] - bmats.A_1_13.data[i][j] - bmats.A_1_14.data[i][j] - bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - bmats.A_1_17.data[i][j] - bmats.A_1_18.data[i][j] - bmats.A_1_19.data[i][j] + 11*bmats.A_1_20.data[i][j] - bmats.A_1_21.data[i][j] - bmats.A_1_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_1_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_9.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
