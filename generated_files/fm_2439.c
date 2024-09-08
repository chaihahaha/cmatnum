#include "fm_2439.h"

inline int fm_2439(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_6.data[i][j] + 11*bmats.A_15_7.data[i][j] + bmats.A_18_12.data[i][j] - 11*bmats.A_18_13.data[i][j] + bmats.A_18_21.data[i][j] + 11*bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] - bmats.Ax2862.data[i][j] - bmats.Ax968.data[i][j] - bmats.Ax98.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_13_4.data[i][j] + bmats.B_15_18.data[i][j] + bmats.B_7_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
