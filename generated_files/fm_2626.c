#include "fm_2626.h"

inline int fm_2626(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_16_12.data[i][j] + bmats.A_16_16.data[i][j] + bmats.A_16_18.data[i][j] + bmats.A_16_22.data[i][j] + 11*bmats.A_1_21.data[i][j] - bmats.A_1_22.data[i][j] - bmats.A_21_4.data[i][j] + 11*bmats.A_21_5.data[i][j] - bmats.Ax2.data[i][j] - bmats.Ax2997.data[i][j] - bmats.Ax932.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_12_10.data[i][j] + bmats.B_21_16.data[i][j] + bmats.B_5_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
