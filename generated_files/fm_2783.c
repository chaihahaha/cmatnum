#include "fm_2783.h"

inline int fm_2783(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_1.data[i][j] - bmats.A_13_10.data[i][j] - bmats.A_13_11.data[i][j] - bmats.A_13_12.data[i][j] - bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] - bmats.A_13_15.data[i][j] - bmats.A_13_16.data[i][j] - bmats.A_13_17.data[i][j] - bmats.A_13_18.data[i][j] - bmats.A_13_19.data[i][j] - bmats.A_13_2.data[i][j] - bmats.A_13_20.data[i][j] - bmats.A_13_21.data[i][j] - bmats.A_13_22.data[i][j] - bmats.A_13_3.data[i][j] - bmats.A_13_4.data[i][j] - bmats.A_13_5.data[i][j] - bmats.A_13_6.data[i][j] - bmats.A_13_7.data[i][j] - bmats.A_13_8.data[i][j] - bmats.A_13_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_2_12.data[i][j]-bmats.B_2_13.data[i][j]-bmats.B_2_14.data[i][j]-bmats.B_2_15.data[i][j]-bmats.B_2_16.data[i][j]-bmats.B_2_17.data[i][j]-bmats.B_2_18.data[i][j]-bmats.B_2_19.data[i][j]-bmats.B_2_20.data[i][j]-bmats.B_2_21.data[i][j]-bmats.B_2_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

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
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
