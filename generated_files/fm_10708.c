#include "fm_10708.h"

inline int fm_10708(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_1_27.data[i][j] - bmats.A_1_28.data[i][j] - bmats.Ax2309.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
