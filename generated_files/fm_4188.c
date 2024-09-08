#include "fm_4188.h"

inline int fm_4188(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_10.data[i][j] - bmats.A_18_11.data[i][j] - bmats.A_18_17.data[i][j] + 11*bmats.A_18_18.data[i][j] - bmats.A_7_17.data[i][j] + 11*bmats.A_7_18.data[i][j] - bmats.Ax156.data[i][j] - bmats.Ax46.data[i][j] - bmats.Ax639.data[i][j] - bmats.Ax78.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_18_12.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_18_14.data[i][j] - bmats.B_18_15.data[i][j] - bmats.B_18_16.data[i][j] - bmats.B_18_17.data[i][j] - bmats.B_18_18.data[i][j] - bmats.B_18_19.data[i][j] - bmats.B_18_20.data[i][j] - bmats.B_18_21.data[i][j] - bmats.B_18_22.data[i][j] + bmats.B_18_7.data[i][j] - bmats.B_6_18.data[i][j] - bmats.Bx4260.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_18_18.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
