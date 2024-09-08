#include "fm_1509.h"

inline int fm_1509(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_10_21.data[i][j] + 11*bmats.A_10_22.data[i][j] + bmats.A_11_11.data[i][j] + bmats.A_11_2.data[i][j] - 11*bmats.A_11_3.data[i][j] + 11*bmats.A_14_10.data[i][j] - bmats.A_14_11.data[i][j] - bmats.Ax2416.data[i][j] - bmats.Ax279.data[i][j] - bmats.Ax505.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_11.data[i][j] + bmats.B_22_3.data[i][j] + bmats.B_3_21.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
