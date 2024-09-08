#include "fm_1236.h"

inline int fm_1236(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_13.data[i][j] + 11*bmats.A_10_14.data[i][j] + 11*bmats.A_17_10.data[i][j] - bmats.A_17_11.data[i][j] - 11*bmats.A_3_6.data[i][j] + bmats.A_3_7.data[i][j] - bmats.Ax1369.data[i][j] - bmats.Ax2285.data[i][j] - bmats.Ax503.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_3.data[i][j] + bmats.B_14_6.data[i][j] + bmats.B_6_21.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
