#include "fm_1681.h"

inline int fm_1681(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_19_31.data[i][j] - 16*bmats.A_30_19.data[i][j] + bmats.A_30_20.data[i][j] - 17*bmats.A_31_19.data[i][j] + bmats.Ax1569.data[i][j] + bmats.Ax4554.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_19.data[i][j] - bmats.B_18_19.data[i][j] - bmats.B_19_19.data[i][j] + bmats.B_19_31.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_22_19.data[i][j] - bmats.B_23_19.data[i][j] - bmats.B_24_19.data[i][j] - bmats.B_25_19.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_27_19.data[i][j] - bmats.B_28_19.data[i][j] - bmats.B_29_19.data[i][j] - bmats.B_30_19.data[i][j] - bmats.B_31_17.data[i][j] - bmats.B_31_18.data[i][j] - 2*bmats.B_31_19.data[i][j] - bmats.B_31_20.data[i][j] - bmats.B_31_21.data[i][j] - bmats.B_31_22.data[i][j] - bmats.B_31_23.data[i][j] - bmats.B_31_24.data[i][j] - bmats.B_31_25.data[i][j] - bmats.B_31_26.data[i][j] - bmats.B_31_27.data[i][j] - bmats.B_31_28.data[i][j] - bmats.B_31_29.data[i][j] - bmats.B_31_30.data[i][j] - bmats.B_31_31.data[i][j] - bmats.B_31_32.data[i][j] - bmats.B_32_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
