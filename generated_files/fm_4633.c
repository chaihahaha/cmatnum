#include "fm_4633.h"

inline int fm_4633(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_13_15.data[i][j] - bmats.A_13_16.data[i][j] - 2*bmats.A_15_12.data[i][j] + 10*bmats.A_15_13.data[i][j] - bmats.Ax3522.data[i][j] - bmats.Ax861.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_15.data[i][j] + bmats.B_15_13.data[i][j] + bmats.B_15_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
