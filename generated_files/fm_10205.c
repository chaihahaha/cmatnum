#include "fm_10205.h"

inline int fm_10205(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_29.data[i][j] - bmats.A_10_30.data[i][j] - bmats.Ax426.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_13.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_26.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
