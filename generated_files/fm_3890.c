#include "fm_3890.h"

inline int fm_3890(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_15_21.data[i][j] - 11*bmats.A_15_22.data[i][j] - 12*bmats.A_16_22.data[i][j] + 12*bmats.A_22_16.data[i][j] + bmats.Ax3199.data[i][j] + bmats.Ax776.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_22.data[i][j] - bmats.B_13_22.data[i][j] - bmats.B_14_22.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_16_12.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_16_16.data[i][j] - bmats.B_16_17.data[i][j] - bmats.B_16_18.data[i][j] - bmats.B_16_19.data[i][j] - bmats.B_16_20.data[i][j] - bmats.B_16_21.data[i][j] - 2*bmats.B_16_22.data[i][j] - bmats.B_17_22.data[i][j] - bmats.B_18_22.data[i][j] - bmats.B_19_22.data[i][j] - bmats.B_20_22.data[i][j] - bmats.B_21_22.data[i][j] + bmats.B_22_16.data[i][j] - bmats.B_22_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
