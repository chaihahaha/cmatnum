#include "fm_11834.h"

inline int fm_11834(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_6_19.data[i][j] - bmats.A_6_20.data[i][j] - bmats.Ax4099.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_6_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_22.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}