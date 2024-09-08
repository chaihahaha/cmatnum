#include "fm_3834.h"

inline int fm_3834(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_11_21.data[i][j] - bmats.A_11_22.data[i][j] - bmats.A_21_10.data[i][j] - bmats.A_21_11.data[i][j] - bmats.A_22_21.data[i][j] + 11*bmats.A_22_22.data[i][j] - bmats.Ax3100.data[i][j] - bmats.Ax511.data[i][j] - bmats.Ax561.data[i][j] - bmats.Ax606.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_22.data[i][j] - bmats.B_11_22.data[i][j] - bmats.B_21_12.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_21_14.data[i][j] - bmats.B_21_15.data[i][j] - bmats.B_21_16.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_21_21.data[i][j] - bmats.B_21_22.data[i][j] + bmats.B_22_10.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_9_22.data[i][j] - bmats.Bx4114.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
