#include "fm_795.h"

inline int fm_795(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_10_27.data[i][j] - bmats.A_10_28.data[i][j] - bmats.A_17_25.data[i][j] + 16*bmats.A_17_26.data[i][j] - bmats.A_26_25.data[i][j] + 16*bmats.A_26_26.data[i][j] - bmats.A_27_15.data[i][j] - bmats.A_27_16.data[i][j] - bmats.Ax2288.data[i][j] - bmats.Ax239.data[i][j] - bmats.Ax2963.data[i][j] - bmats.Ax58.data[i][j] - bmats.Ax685.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_26_11.data[i][j] - bmats.B_27_17.data[i][j] - bmats.B_27_18.data[i][j] - bmats.B_27_23.data[i][j] - bmats.Bx7184.data[i][j] - bmats.Bx7425.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_26.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
