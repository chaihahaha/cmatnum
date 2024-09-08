#include "fm_310.h"

inline int fm_310(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_14_10.data[i][j] + bmats.A_14_5.data[i][j] - bmats.A_21_21.data[i][j] - bmats.A_21_22.data[i][j] - bmats.Ax1505.data[i][j] - bmats.Ax551.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_12.data[i][j] - bmats.B_10_13.data[i][j] - bmats.B_10_14.data[i][j] - bmats.B_10_15.data[i][j] - bmats.B_10_16.data[i][j] - bmats.B_10_17.data[i][j] - bmats.B_10_18.data[i][j] - bmats.B_10_19.data[i][j] - bmats.B_10_20.data[i][j] - bmats.B_10_21.data[i][j] - bmats.B_10_22.data[i][j] - bmats.B_12_3.data[i][j] - bmats.B_13_3.data[i][j] + bmats.B_14_21.data[i][j] - bmats.B_14_3.data[i][j] - bmats.B_15_3.data[i][j] - bmats.B_16_3.data[i][j] - bmats.B_17_3.data[i][j] - bmats.B_18_3.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_20_3.data[i][j] - bmats.B_21_3.data[i][j] - bmats.B_22_3.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
