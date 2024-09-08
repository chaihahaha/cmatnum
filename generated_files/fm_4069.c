#include "fm_4069.h"

inline int fm_4069(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_19_11.data[i][j] - bmats.A_22_21.data[i][j] - bmats.A_22_22.data[i][j] - bmats.Ax3150.data[i][j] - bmats.Ax606.data[i][j] - bmats.Ax694.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_11_12.data[i][j] - bmats.B_11_13.data[i][j] - bmats.B_11_14.data[i][j] - bmats.B_11_15.data[i][j] - bmats.B_11_16.data[i][j] - bmats.B_11_17.data[i][j] - bmats.B_11_18.data[i][j] - bmats.B_11_19.data[i][j] - bmats.B_11_20.data[i][j] - bmats.B_11_21.data[i][j] - bmats.B_11_22.data[i][j] - bmats.B_18_8.data[i][j] + bmats.B_19_22.data[i][j] - bmats.B_19_8.data[i][j] - bmats.Bx4580.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
