#include "fm_3538.h"

inline int fm_3538(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_13.data[i][j] + 11*bmats.A_11_14.data[i][j] - bmats.Ax1360.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_3.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_11.data[i][j]+=-1 * m.data[i][j];
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
        bmats.C_4_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_3.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
