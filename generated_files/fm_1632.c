#include "fm_1632.h"

inline int fm_1632(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 17*bmats.A_20_21.data[i][j] - 17*bmats.A_21_20.data[i][j] + bmats.A_22_19.data[i][j] - 16*bmats.A_22_20.data[i][j] + bmats.Ax199.data[i][j] + bmats.Ax4469.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.B_17_20.data[i][j] - bmats.B_18_20.data[i][j] - bmats.B_19_20.data[i][j] + bmats.B_20_21.data[i][j] - bmats.B_21_17.data[i][j] - bmats.B_21_18.data[i][j] - bmats.B_21_19.data[i][j] - 2*bmats.B_21_20.data[i][j] - bmats.B_21_21.data[i][j] - bmats.B_21_22.data[i][j] - bmats.B_21_23.data[i][j] - bmats.B_21_24.data[i][j] - bmats.B_21_25.data[i][j] - bmats.B_21_26.data[i][j] - bmats.B_21_27.data[i][j] - bmats.B_21_28.data[i][j] - bmats.B_21_29.data[i][j] - bmats.B_21_30.data[i][j] - bmats.B_21_31.data[i][j] - bmats.B_21_32.data[i][j] - bmats.B_23_20.data[i][j] - bmats.B_27_20.data[i][j] - bmats.B_29_20.data[i][j] - bmats.B_31_20.data[i][j] - bmats.B_32_20.data[i][j] - bmats.Bx11895.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}