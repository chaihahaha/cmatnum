#include "fm_8434.h"

inline int fm_8434(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_7.data[i][j] + 16*bmats.A_18_8.data[i][j] + bmats.A_24_18.data[i][j] - 16*bmats.A_24_19.data[i][j] + bmats.A_24_20.data[i][j] + bmats.A_24_24.data[i][j] + bmats.A_24_26.data[i][j] + bmats.A_24_27.data[i][j] + bmats.A_24_28.data[i][j] - bmats.A_3_17.data[i][j] + 16*bmats.A_3_18.data[i][j] - bmats.Ax3417.data[i][j] - bmats.Ax4589.data[i][j] - bmats.Ax6947.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_24.data[i][j] + bmats.B_19_2.data[i][j] + bmats.B_8_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}