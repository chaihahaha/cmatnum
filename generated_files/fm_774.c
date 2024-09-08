#include "fm_774.h"

inline int fm_774(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - 11*bmats.A_4_10.data[i][j] + bmats.A_4_11.data[i][j] - bmats.Ax1312.data[i][j] - bmats.Ax1753.data[i][j] - bmats.Ax980.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_12.data[i][j] + bmats.B_15_10.data[i][j] + bmats.B_1_4.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_4.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
