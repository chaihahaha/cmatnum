#include "fm_1400.h"

inline int fm_1400(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_21_14.data[i][j] - bmats.A_30_31.data[i][j] - bmats.A_30_32.data[i][j] - bmats.Ax1674.data[i][j] - bmats.Ax4126.data[i][j] - bmats.Ax604.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_14_17.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_20_5.data[i][j] + bmats.B_21_30.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_28_5.data[i][j] - bmats.B_30_5.data[i][j] - bmats.B_31_5.data[i][j] - bmats.B_32_5.data[i][j] - bmats.Bx11450.data[i][j] - bmats.Bx2496.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
