#include "fm_1624.h"

inline int fm_1624(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_19_19.data[i][j] - 16*bmats.A_19_20.data[i][j] - bmats.A_20_28.data[i][j] - bmats.A_20_30.data[i][j] + bmats.Ax4354.data[i][j] + bmats.Ax4378.data[i][j] + bmats.Ax4467.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_20.data[i][j] - bmats.B_18_20.data[i][j] - bmats.B_19_20.data[i][j] - bmats.B_20_17.data[i][j] - bmats.B_20_18.data[i][j] - bmats.B_20_19.data[i][j] - bmats.B_20_20.data[i][j] - bmats.B_20_21.data[i][j] - bmats.B_20_22.data[i][j] - bmats.B_20_23.data[i][j] - bmats.B_20_24.data[i][j] - bmats.B_20_25.data[i][j] - bmats.B_20_26.data[i][j] - bmats.B_20_27.data[i][j] - bmats.B_20_28.data[i][j] - bmats.B_20_29.data[i][j] - bmats.B_20_30.data[i][j] - bmats.B_20_31.data[i][j] - bmats.B_20_32.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_22_20.data[i][j] - bmats.B_23_20.data[i][j] - bmats.B_24_20.data[i][j] - bmats.B_25_20.data[i][j] - bmats.B_26_20.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_28_20.data[i][j] - bmats.B_29_20.data[i][j] - bmats.B_30_20.data[i][j] - bmats.B_31_20.data[i][j] - bmats.B_32_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
