#include "fm_2074.h"

inline int fm_2074(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_14_15.data[i][j] - 16*bmats.A_14_16.data[i][j] + 16*bmats.A_32_7.data[i][j] - bmats.A_32_8.data[i][j] - bmats.A_7_29.data[i][j] + 16*bmats.A_7_30.data[i][j] - bmats.Ax1007.data[i][j] - bmats.Ax3393.data[i][j] - bmats.Ax417.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_16_23.data[i][j] + bmats.B_30_16.data[i][j] + bmats.B_7_14.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_32_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_23.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}