#include "fm_353.h"

inline int fm_353(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 12*bmats.A_14_15.data[i][j] - 12*bmats.A_15_14.data[i][j] + bmats.A_16_13.data[i][j] - 11*bmats.A_16_14.data[i][j] + bmats.Ax1112.data[i][j] + bmats.Ax1564.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_14.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_14_14.data[i][j] + bmats.B_14_15.data[i][j] - bmats.B_15_12.data[i][j] - bmats.B_15_13.data[i][j] - 2*bmats.B_15_14.data[i][j] - bmats.B_15_15.data[i][j] - bmats.B_15_16.data[i][j] - bmats.B_15_17.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_15_20.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_16_14.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_19_14.data[i][j] - bmats.B_20_14.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_22_14.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
