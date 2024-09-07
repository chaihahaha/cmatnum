#include "fm_3332.h"

inline int fm_3332(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_7_12.data[i][j] - bmats.A_7_13.data[i][j] - bmats.A_7_14.data[i][j] - bmats.A_7_15.data[i][j] - bmats.A_7_16.data[i][j] + 11*bmats.A_7_17.data[i][j] - bmats.A_7_18.data[i][j] - bmats.A_7_19.data[i][j] - bmats.A_7_20.data[i][j] - bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_7_6.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_6.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
