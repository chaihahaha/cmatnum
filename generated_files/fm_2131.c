#include "fm_2131.h"

inline int fm_2131(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_20_12.data[i][j] + bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] - 11*bmats.A_20_18.data[i][j] + bmats.A_20_20.data[i][j] - bmats.A_21_8.data[i][j] + 11*bmats.A_21_9.data[i][j] + 11*bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j] - bmats.Ax2063.data[i][j] - bmats.Ax2715.data[i][j] - bmats.Ax636.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_18_10.data[i][j] + bmats.B_21_20.data[i][j] + bmats.B_9_18.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_7.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
