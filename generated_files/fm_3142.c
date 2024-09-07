#include "fm_3142.h"

inline int fm_3142(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_1.data[i][j] - bmats.A_18_10.data[i][j] - bmats.A_18_11.data[i][j] - bmats.A_18_2.data[i][j] - bmats.A_18_3.data[i][j] - bmats.A_18_4.data[i][j] - bmats.A_18_5.data[i][j] - bmats.A_18_6.data[i][j] - bmats.A_18_7.data[i][j] + 11*bmats.A_18_8.data[i][j] - bmats.A_18_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_18_19.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_19.data[i][j]+=12 * m.data[i][j];
        bmats.C_12_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
