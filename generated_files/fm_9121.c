#include "fm_9121.h"

inline int fm_9121(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_19.data[i][j] + 16*bmats.A_16_20.data[i][j] - bmats.A_20_11.data[i][j] + 16*bmats.A_20_12.data[i][j] + bmats.A_28_17.data[i][j] - 16*bmats.A_28_32.data[i][j] - bmats.Ax2275.data[i][j] - bmats.Ax2371.data[i][j] - bmats.Ax4313.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_32.data[i][j] + bmats.B_20_28.data[i][j] + bmats.B_32_4.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}