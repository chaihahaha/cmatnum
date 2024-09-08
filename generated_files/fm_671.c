#include "fm_671.h"

inline int fm_671(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_11_10.data[i][j] + bmats.A_11_11.data[i][j] + 11*bmats.A_21_4.data[i][j] - bmats.A_21_5.data[i][j] - bmats.A_4_21.data[i][j] + 11*bmats.A_4_22.data[i][j] - bmats.Ax1888.data[i][j] - bmats.Ax732.data[i][j] - bmats.Ax932.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_15.data[i][j] + bmats.B_22_10.data[i][j] + bmats.B_4_11.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
