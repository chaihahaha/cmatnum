#include "fm_4649.h"

inline int fm_4649(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 10*bmats.A_11_1.data[i][j] - 2*bmats.A_11_10.data[i][j] + 10*bmats.A_11_11.data[i][j] - 2*bmats.A_11_2.data[i][j] - 2*bmats.A_11_3.data[i][j] - 2*bmats.A_11_4.data[i][j] - 2*bmats.A_11_5.data[i][j] - 2*bmats.A_11_6.data[i][j] - 2*bmats.A_11_7.data[i][j] - 2*bmats.A_11_8.data[i][j] - 2*bmats.A_11_9.data[i][j] - bmats.A_1_1.data[i][j] - bmats.A_1_10.data[i][j] + 11*bmats.A_1_11.data[i][j] - bmats.A_1_2.data[i][j] - bmats.A_1_3.data[i][j] - bmats.A_1_4.data[i][j] - bmats.A_1_5.data[i][j] - bmats.A_1_6.data[i][j] - bmats.A_1_7.data[i][j] - bmats.A_1_8.data[i][j] - bmats.A_1_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_1.data[i][j]+bmats.B_1_11.data[i][j]+bmats.B_11_11.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
