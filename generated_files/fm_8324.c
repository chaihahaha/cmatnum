#include "fm_8324.h"

inline int fm_8324(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_23.data[i][j] + 16*bmats.A_11_24.data[i][j] + bmats.A_24_26.data[i][j] - 16*bmats.A_24_27.data[i][j] + bmats.A_24_29.data[i][j] - bmats.A_24_7.data[i][j] + 16*bmats.A_24_8.data[i][j] - bmats.Ax2729.data[i][j] - bmats.Ax3399.data[i][j] - bmats.Ax6919.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_24_24.data[i][j] + bmats.B_27_8.data[i][j] + bmats.B_8_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}