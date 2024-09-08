#include "fm_257.h"

inline int fm_257(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_15_15.data[i][j] - 11*bmats.A_15_16.data[i][j] - bmats.A_5_22.data[i][j] + bmats.Ax1239.data[i][j] + bmats.Ax807.data[i][j] + bmats.Ax867.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_15.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_14_15.data[i][j] - bmats.B_15_15.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_18_15.data[i][j] - bmats.B_19_15.data[i][j] - bmats.B_20_15.data[i][j] - bmats.B_21_15.data[i][j] - bmats.B_22_15.data[i][j] + bmats.B_4_16.data[i][j] - bmats.Bx2401.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
