#include "fm_4120.h"

inline int fm_4120(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -12*bmats.A_17_19.data[i][j] + 12*bmats.A_19_17.data[i][j] - 11*bmats.A_22_19.data[i][j] + bmats.A_22_20.data[i][j] + bmats.Ax3140.data[i][j] + bmats.Ax3278.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_19.data[i][j] - bmats.B_13_19.data[i][j] - bmats.B_14_19.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_16_19.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_17_16.data[i][j] - bmats.B_17_17.data[i][j] - bmats.B_17_18.data[i][j] - 2*bmats.B_17_19.data[i][j] - bmats.B_17_20.data[i][j] - bmats.B_17_21.data[i][j] - bmats.B_17_22.data[i][j] - bmats.B_18_19.data[i][j] + bmats.B_19_17.data[i][j] - bmats.B_19_19.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_22_19.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_19_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
