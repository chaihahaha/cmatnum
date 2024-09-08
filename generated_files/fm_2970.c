#include "fm_2970.h"

inline int fm_2970(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j] - bmats.Ax329.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_9_10.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_10.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
