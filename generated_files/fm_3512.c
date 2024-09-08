#include "fm_3512.h"

inline int fm_3512(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_17_4.data[i][j] - bmats.A_17_5.data[i][j] - bmats.Ax730.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_17_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_15.data[i][j]+=12 * m.data[i][j];
        bmats.C_12_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_17.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
