#include "fm_14392.h"

inline int fm_14392(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_21_25.data[i][j] - bmats.A_21_26.data[i][j] - bmats.A_25_29.data[i][j] + 16*bmats.A_25_30.data[i][j] + 16*bmats.A_30_21.data[i][j] - bmats.A_30_22.data[i][j] - bmats.Ax1100.data[i][j] - bmats.Ax1635.data[i][j] - bmats.Ax251.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_25.data[i][j] + bmats.B_25_30.data[i][j] + bmats.B_30_21.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
