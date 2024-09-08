#include "fm_9993.h"

inline int fm_9993(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_9_31.data[i][j] - bmats.A_9_32.data[i][j] - bmats.Ax769.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_9_15.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_25.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
