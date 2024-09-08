#include "fm_8403.h"

inline int fm_8403(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_7.data[i][j] + 16*bmats.A_18_8.data[i][j] + bmats.A_24_18.data[i][j] + bmats.A_24_20.data[i][j] + bmats.A_24_22.data[i][j] - 16*bmats.A_24_23.data[i][j] + bmats.A_24_24.data[i][j] + bmats.A_24_25.data[i][j] + bmats.A_24_26.data[i][j] + bmats.A_24_27.data[i][j] + bmats.A_24_28.data[i][j] - bmats.A_7_17.data[i][j] + 16*bmats.A_7_18.data[i][j] - bmats.Ax3417.data[i][j] - bmats.Ax3878.data[i][j] - bmats.Ax6959.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_24.data[i][j] + bmats.B_23_2.data[i][j] + bmats.B_8_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_24.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
