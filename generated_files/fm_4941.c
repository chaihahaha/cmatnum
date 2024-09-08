#include "fm_4941.h"

inline int fm_4941(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_11_5.data[i][j] + bmats.A_11_6.data[i][j] - bmats.A_21_7.data[i][j] + 16*bmats.A_21_8.data[i][j] + 16*bmats.A_8_27.data[i][j] - bmats.A_8_28.data[i][j] - bmats.Ax2306.data[i][j] - bmats.Ax3408.data[i][j] - bmats.Ax5576.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_5.data[i][j] + bmats.B_5_24.data[i][j] + bmats.B_8_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_24.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
