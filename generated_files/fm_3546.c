#include "fm_3546.h"

inline int fm_3546(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - bmats.Ax980.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_1_4.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_4.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
