#include "fm_2029.h"

inline int fm_2029(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_17_17.data[i][j] - bmats.A_17_18.data[i][j] + 16*bmats.A_18_17.data[i][j] - bmats.A_18_18.data[i][j] + 16*bmats.A_1_21.data[i][j] - bmats.A_1_22.data[i][j] - bmats.A_21_15.data[i][j] - bmats.A_21_16.data[i][j] - bmats.Ax158.data[i][j] - bmats.Ax3856.data[i][j] - bmats.Ax4655.data[i][j] - bmats.Ax4793.data[i][j] - bmats.Ax712.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_16_17.data[i][j] + bmats.B_17_5.data[i][j] - bmats.B_1_17.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_21_19.data[i][j] - bmats.B_21_20.data[i][j] - bmats.B_21_21.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_21_24.data[i][j] - bmats.B_21_25.data[i][j] - bmats.B_21_26.data[i][j] - bmats.B_21_27.data[i][j] - bmats.B_21_28.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_21_30.data[i][j] - bmats.B_21_31.data[i][j] - bmats.B_21_32.data[i][j] - bmats.B_2_17.data[i][j] - bmats.Bx12860.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}