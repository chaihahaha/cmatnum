#include "fm_9389.h"

inline int fm_9389(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_27_17.data[i][j] + bmats.A_27_18.data[i][j] - 16*bmats.A_27_24.data[i][j] + bmats.A_27_25.data[i][j] + bmats.A_27_27.data[i][j] + 16*bmats.A_32_11.data[i][j] - bmats.A_32_12.data[i][j] - bmats.A_8_31.data[i][j] + 16*bmats.A_8_32.data[i][j] - bmats.Ax2239.data[i][j] - bmats.Ax6823.data[i][j] - bmats.Ax766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_24.data[i][j] + bmats.B_24_16.data[i][j] + bmats.B_32_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_27.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
