#include "fm_3398.h"

inline int fm_3398(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_8_15.data[i][j] + 11*bmats.A_8_16.data[i][j] - bmats.Ax959.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_8_5.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_5.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
