#include "fm_15133.h"

inline int fm_15133(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_15.data[i][j] - bmats.A_11_16.data[i][j] + bmats.A_16_17.data[i][j] + bmats.A_16_18.data[i][j] + bmats.A_16_19.data[i][j] + bmats.A_16_20.data[i][j] + bmats.A_16_21.data[i][j] + bmats.A_16_22.data[i][j] + bmats.A_16_23.data[i][j] + bmats.A_16_24.data[i][j] + bmats.A_16_25.data[i][j] + bmats.A_16_26.data[i][j] - 16*bmats.A_16_27.data[i][j] + bmats.A_16_28.data[i][j] + bmats.A_16_29.data[i][j] + bmats.A_16_30.data[i][j] + bmats.A_16_31.data[i][j] + bmats.A_16_32.data[i][j] - bmats.Ax562.data[i][j] - bmats.Ax7799.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_15_32.data[i][j] + bmats.B_16_11.data[i][j] - bmats.B_16_32.data[i][j] - bmats.B_27_10.data[i][j] - bmats.B_27_11.data[i][j] - bmats.B_27_12.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_27_14.data[i][j] - bmats.B_27_15.data[i][j] - bmats.B_27_16.data[i][j] - bmats.Bx13238.data[i][j] - bmats.Bx7427.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}