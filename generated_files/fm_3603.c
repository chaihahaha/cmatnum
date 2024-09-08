#include "fm_3603.h"

inline int fm_3603(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_13.data[i][j] + 11*bmats.A_10_14.data[i][j] - bmats.Ax1369.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_3.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
