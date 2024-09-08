#include "fm_10797.h"

inline int fm_10797(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_27_10.data[i][j] - bmats.A_27_9.data[i][j] - bmats.Ax2671.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_26.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_11.data[i][j]+=17 * m.data[i][j];
        bmats.C_27_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
