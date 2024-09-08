#include "fm_4361.h"

inline int fm_4361(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_13_12.data[i][j] + bmats.A_13_13.data[i][j] - 11*bmats.A_13_18.data[i][j] + 11*bmats.A_21_2.data[i][j] - bmats.A_21_3.data[i][j] + 11*bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j] - bmats.Ax1344.data[i][j] - bmats.Ax3371.data[i][j] - bmats.Ax636.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_18_10.data[i][j] + bmats.B_21_13.data[i][j] + bmats.B_2_18.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_21.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
