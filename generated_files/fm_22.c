#include "fm_22.h"

inline int fm_22(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_21_27.data[i][j] + 16*bmats.A_21_28.data[i][j] + 16*bmats.A_23_21.data[i][j] - bmats.A_23_22.data[i][j] + 16*bmats.A_28_23.data[i][j] - bmats.A_28_24.data[i][j] - bmats.Ax39.data[i][j] - bmats.Ax82.data[i][j] - bmats.Ax93.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_28.data[i][j] + bmats.B_23_21.data[i][j] + bmats.B_28_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}