#include "fm_7096.h"

inline int fm_7096(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_15_29.data[i][j] - bmats.A_15_30.data[i][j] + bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] + bmats.A_21_21.data[i][j] + bmats.A_21_22.data[i][j] - 16*bmats.A_21_31.data[i][j] + bmats.A_21_32.data[i][j] + 16*bmats.A_29_5.data[i][j] - bmats.A_29_6.data[i][j] - bmats.Ax2077.data[i][j] - bmats.Ax396.data[i][j] - bmats.Ax6068.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_29_21.data[i][j] + bmats.B_31_13.data[i][j] + bmats.B_5_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
