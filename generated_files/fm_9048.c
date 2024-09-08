#include "fm_9048.h"

inline int fm_9048(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_24_10.data[i][j] + 16*bmats.A_24_9.data[i][j] + bmats.A_25_22.data[i][j] - 16*bmats.A_25_23.data[i][j] + bmats.A_25_25.data[i][j] + bmats.A_25_31.data[i][j] + bmats.A_25_32.data[i][j] - bmats.A_7_23.data[i][j] + 16*bmats.A_7_24.data[i][j] - bmats.Ax2807.data[i][j] - bmats.Ax3427.data[i][j] - bmats.Ax6866.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_23_8.data[i][j] + bmats.B_24_25.data[i][j] + bmats.B_9_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_25.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
