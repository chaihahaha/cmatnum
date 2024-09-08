#include "fm_3950.h"

inline int fm_3950(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_15.data[i][j] + 11*bmats.A_10_16.data[i][j] - bmats.A_16_10.data[i][j] - bmats.A_16_11.data[i][j] + 11*bmats.A_21_21.data[i][j] - bmats.A_21_22.data[i][j] - bmats.Ax3084.data[i][j] - bmats.Ax551.data[i][j] - bmats.Ax791.data[i][j] - bmats.Ax965.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_21.data[i][j] - bmats.B_16_12.data[i][j] - bmats.B_16_13.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_16_15.data[i][j] - bmats.B_16_16.data[i][j] - bmats.B_16_17.data[i][j] - bmats.B_16_18.data[i][j] - bmats.B_16_19.data[i][j] - bmats.B_16_20.data[i][j] - bmats.B_16_21.data[i][j] - bmats.B_16_22.data[i][j] + bmats.B_21_5.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_8_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx4092.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
