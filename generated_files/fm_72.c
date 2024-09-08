#include "fm_72.h"

inline int fm_72(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_4_6.data[i][j] + bmats.A_4_7.data[i][j] + 12*bmats.A_6_9.data[i][j] - 12*bmats.A_9_6.data[i][j] + bmats.Ax24.data[i][j] + bmats.Ax704.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_6.data[i][j] - bmats.B_11_6.data[i][j] - bmats.B_1_6.data[i][j] - bmats.B_2_6.data[i][j] - bmats.B_3_6.data[i][j] - bmats.B_4_6.data[i][j] - bmats.B_5_6.data[i][j] - bmats.B_6_6.data[i][j] + bmats.B_6_9.data[i][j] - bmats.B_7_6.data[i][j] - bmats.B_8_6.data[i][j] - bmats.B_9_1.data[i][j] - bmats.B_9_10.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_2.data[i][j] - bmats.B_9_3.data[i][j] - bmats.B_9_4.data[i][j] - bmats.B_9_5.data[i][j] - 2*bmats.B_9_6.data[i][j] - bmats.B_9_7.data[i][j] - bmats.B_9_8.data[i][j] - bmats.B_9_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
