#include "fm_1551.h"

inline int fm_1551(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_1_19.data[i][j] + 11*bmats.A_1_20.data[i][j] + bmats.A_9_2.data[i][j] - 11*bmats.A_9_3.data[i][j] + bmats.A_9_9.data[i][j] - bmats.Ax1654.data[i][j] - bmats.Ax1851.data[i][j] - bmats.Ax2432.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_1_9.data[i][j] + bmats.B_20_3.data[i][j] + bmats.B_3_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_9.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
