#include "fm_7403.h"

inline int fm_7403(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_31.data[i][j] + 16*bmats.A_14_32.data[i][j] - 16*bmats.A_17_30.data[i][j] + bmats.A_17_31.data[i][j] + 16*bmats.A_32_1.data[i][j] - bmats.A_32_2.data[i][j] - bmats.Ax4670.data[i][j] - bmats.Ax4905.data[i][j] - bmats.Ax745.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_30.data[i][j] + bmats.B_30_16.data[i][j] + bmats.B_32_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}