#include "fm_2513.h"

inline int fm_2513(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_2_19.data[i][j] - bmats.A_2_20.data[i][j] - bmats.A_31_1.data[i][j] + 16*bmats.A_31_2.data[i][j] - 16*bmats.A_3_15.data[i][j] + bmats.A_3_16.data[i][j] - bmats.Ax4318.data[i][j] - bmats.Ax4620.data[i][j] - bmats.Ax643.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_18.data[i][j] + bmats.B_19_15.data[i][j] + bmats.B_2_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_18.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}