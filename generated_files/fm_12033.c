#include "fm_12033.h"

inline int fm_12033(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_15.data[i][j] + 16*bmats.A_20_16.data[i][j] - 16*bmats.A_32_22.data[i][j] + bmats.A_32_23.data[i][j] + bmats.A_32_28.data[i][j] + bmats.A_32_29.data[i][j] + bmats.A_32_32.data[i][j] - bmats.A_6_19.data[i][j] + 16*bmats.A_6_20.data[i][j] - bmats.Ax4099.data[i][j] - bmats.Ax5998.data[i][j] - bmats.Ax709.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_22.data[i][j] + bmats.B_20_32.data[i][j] + bmats.B_22_4.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}