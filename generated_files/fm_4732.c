#include "fm_4732.h"

inline int fm_4732(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_8_8.data[i][j] + 11*bmats.A_8_9.data[i][j] - 2*bmats.A_9_7.data[i][j] + 10*bmats.A_9_8.data[i][j] - bmats.Ax3126.data[i][j] - bmats.Ax3557.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_8_9.data[i][j] + bmats.B_9_8.data[i][j] + bmats.B_9_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
