#include "fm_4739.h"

inline int fm_4739(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_4.data[i][j] + 11*bmats.A_10_5.data[i][j] + 11*bmats.A_1_10.data[i][j] - bmats.A_1_11.data[i][j] - bmats.Ax1267.data[i][j] - bmats.Ax178.data[i][j] - bmats.Ax888.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_5.data[i][j] + bmats.B_1_10.data[i][j] + bmats.B_5_1.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
