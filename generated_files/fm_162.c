#include "fm_162.h"

inline int fm_162(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_16_6.data[i][j] + bmats.A_16_7.data[i][j] - bmats.A_17_21.data[i][j] - bmats.A_17_22.data[i][j] - bmats.Ax1094.data[i][j] - bmats.Ax515.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_5.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_5.data[i][j] + bmats.B_16_17.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_20_5.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_22_5.data[i][j] - bmats.Bx1597.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
