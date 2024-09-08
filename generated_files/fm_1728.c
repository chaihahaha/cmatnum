#include "fm_1728.h"

inline int fm_1728(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_3_23.data[i][j] - 16*bmats.A_3_24.data[i][j] - bmats.A_8_15.data[i][j] - bmats.A_8_16.data[i][j] - bmats.Ax4568.data[i][j] - bmats.Ax576.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_10_19.data[i][j] - bmats.B_11_19.data[i][j] - bmats.B_14_19.data[i][j] - bmats.B_24_10.data[i][j] - bmats.B_24_11.data[i][j] - bmats.B_24_12.data[i][j] - bmats.B_24_13.data[i][j] - bmats.B_24_14.data[i][j] - bmats.B_24_9.data[i][j] + bmats.B_3_8.data[i][j] - bmats.Bx12151.data[i][j] - bmats.Bx12422.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
