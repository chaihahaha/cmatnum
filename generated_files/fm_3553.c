#include "fm_3553.h"

inline int fm_3553(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_13_1.data[i][j] - bmats.A_13_10.data[i][j] - bmats.A_13_11.data[i][j] - bmats.A_13_2.data[i][j] - bmats.A_13_3.data[i][j] + 11*bmats.A_13_4.data[i][j] - bmats.A_13_5.data[i][j] - bmats.A_13_6.data[i][j] - bmats.A_13_7.data[i][j] - bmats.A_13_8.data[i][j] - bmats.A_13_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_2_15.data[i][j]+=12 * m.data[i][j];
        bmats.C_12_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_13.data[i][j]+=-1 * m.data[i][j];
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
        bmats.C_15_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_13.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
