#include "fm_9792.h"

inline int fm_9792(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_27.data[i][j] + 16*bmats.A_18_28.data[i][j] - bmats.A_28_27.data[i][j] + 16*bmats.A_28_28.data[i][j] - bmats.Ax2232.data[i][j] - bmats.Ax23.data[i][j] - bmats.Ax61.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.Bx13307.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
