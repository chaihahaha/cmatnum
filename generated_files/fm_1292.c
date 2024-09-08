#include "fm_1292.h"

inline int fm_1292(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_19.data[i][j] + 11*bmats.A_11_20.data[i][j] - bmats.A_16_10.data[i][j] + 11*bmats.A_16_11.data[i][j] + bmats.A_9_4.data[i][j] - 11*bmats.A_9_5.data[i][j] + bmats.A_9_9.data[i][j] - bmats.Ax1997.data[i][j] - bmats.Ax2332.data[i][j] - bmats.Ax791.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_9.data[i][j] + bmats.B_20_5.data[i][j] + bmats.B_5_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_9.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
