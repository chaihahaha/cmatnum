#include "fm_1952.h"

inline int fm_1952(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -17*bmats.A_14_1.data[i][j] + 17*bmats.A_1_14.data[i][j] - 16*bmats.A_9_1.data[i][j] + bmats.A_9_2.data[i][j] + bmats.Ax3341.data[i][j] + bmats.Ax4820.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -2*bmats.B_14_1.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_14_11.data[i][j] - bmats.B_14_12.data[i][j] - bmats.B_14_13.data[i][j] - bmats.B_14_14.data[i][j] - bmats.B_14_15.data[i][j] - bmats.B_14_16.data[i][j] - bmats.B_14_2.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_1.data[i][j] - bmats.B_16_1.data[i][j] + bmats.B_1_14.data[i][j] - bmats.B_4_1.data[i][j] - bmats.B_5_1.data[i][j] - bmats.B_6_1.data[i][j] - bmats.B_7_1.data[i][j] - bmats.Bx12870.data[i][j] - bmats.Bx3105.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
