#include "fm_55.h"

inline int fm_55(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_17_11.data[i][j] - bmats.A_17_21.data[i][j] - bmats.A_17_22.data[i][j] - 11*bmats.A_17_6.data[i][j] - bmats.Ax515.data[i][j] - bmats.Ax609.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_12_6.data[i][j] - bmats.B_13_6.data[i][j] - bmats.B_14_6.data[i][j] - bmats.B_15_6.data[i][j] - bmats.B_16_6.data[i][j] + bmats.B_17_17.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_6_12.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_6_15.data[i][j] - bmats.B_6_16.data[i][j] - bmats.B_6_17.data[i][j] - bmats.B_6_18.data[i][j] - bmats.B_6_19.data[i][j] - bmats.B_6_20.data[i][j] - bmats.B_6_21.data[i][j] - bmats.B_6_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
