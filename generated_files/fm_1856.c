#include "fm_1856.h"

inline int fm_1856(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_17.data[i][j] + 16*bmats.A_17_18.data[i][j] - bmats.A_18_17.data[i][j] + 16*bmats.A_18_18.data[i][j] - bmats.A_26_15.data[i][j] - bmats.A_26_16.data[i][j] - bmats.A_2_25.data[i][j] + 16*bmats.A_2_26.data[i][j] - bmats.Ax158.data[i][j] - bmats.Ax2872.data[i][j] - bmats.Ax4655.data[i][j] - bmats.Ax4666.data[i][j] - bmats.Ax703.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_16_18.data[i][j] + bmats.B_18_10.data[i][j] - bmats.B_1_18.data[i][j] - bmats.B_26_17.data[i][j] - bmats.B_26_18.data[i][j] - bmats.B_26_19.data[i][j] - bmats.B_26_20.data[i][j] - bmats.B_26_21.data[i][j] - bmats.B_26_22.data[i][j] - bmats.B_2_18.data[i][j] - bmats.Bx12672.data[i][j] - bmats.Bx7697.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_18.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
