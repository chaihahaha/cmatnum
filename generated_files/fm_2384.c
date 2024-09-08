#include "fm_2384.h"

inline int fm_2384(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_11_15.data[i][j] + bmats.A_11_16.data[i][j] + 16*bmats.A_1_27.data[i][j] - bmats.A_1_28.data[i][j] + 16*bmats.A_31_1.data[i][j] - bmats.A_31_2.data[i][j] - bmats.Ax2309.data[i][j] - bmats.Ax2694.data[i][j] - bmats.Ax643.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_17.data[i][j] + bmats.B_1_11.data[i][j] + bmats.B_27_15.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
