#include "fm_4686.h"

inline int fm_4686(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_11_6.data[i][j] - bmats.A_11_7.data[i][j] - bmats.A_4_10.data[i][j] + 11*bmats.A_4_11.data[i][j] + 11*bmats.A_6_4.data[i][j] - bmats.A_6_5.data[i][j] - bmats.Ax18.data[i][j] - bmats.Ax758.data[i][j] - bmats.Ax773.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_6.data[i][j] + bmats.B_4_11.data[i][j] + bmats.B_6_4.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
