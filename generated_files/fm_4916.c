#include "fm_4916.h"

inline int fm_4916(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_12_13.data[i][j] + bmats.A_12_16.data[i][j] + bmats.A_12_17.data[i][j] + bmats.A_12_22.data[i][j] + 11*bmats.A_2_17.data[i][j] - bmats.A_2_18.data[i][j] - bmats.Ax162.data[i][j] - bmats.Ax3417.data[i][j] - bmats.Ax989.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_6.data[i][j] + bmats.B_17_12.data[i][j] + bmats.B_1_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
