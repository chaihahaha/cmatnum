#include "fm_13908.h"

inline int fm_13908(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 15*bmats.A_10_2.data[i][j] - 2*bmats.A_10_3.data[i][j] + 16*bmats.A_2_10.data[i][j] - bmats.A_2_9.data[i][j] - bmats.Ax2944.data[i][j] - bmats.Ax8378.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_10.data[i][j] + bmats.B_10_2.data[i][j] + bmats.B_2_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_10.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}