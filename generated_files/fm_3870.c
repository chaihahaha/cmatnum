#include "fm_3870.h"

inline int fm_3870(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_11_14.data[i][j] - 11*bmats.A_11_19.data[i][j] - bmats.A_8_10.data[i][j] - bmats.A_8_11.data[i][j] - bmats.Ax3196.data[i][j] - bmats.Ax696.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_22.data[i][j] - bmats.B_11_22.data[i][j] + bmats.B_11_8.data[i][j] - bmats.B_19_1.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_19_11.data[i][j] - bmats.B_19_2.data[i][j] - bmats.B_19_3.data[i][j] - bmats.B_19_4.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_9_22.data[i][j] - bmats.Bx4114.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_8.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
