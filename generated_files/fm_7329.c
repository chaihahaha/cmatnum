#include "fm_7329.h"

inline int fm_7329(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_27.data[i][j] - bmats.A_13_28.data[i][j] + bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] + bmats.A_21_21.data[i][j] + bmats.A_21_22.data[i][j] - 16*bmats.A_21_29.data[i][j] + bmats.A_21_30.data[i][j] + 16*bmats.A_27_5.data[i][j] - bmats.A_27_6.data[i][j] - bmats.Ax1963.data[i][j] - bmats.Ax2780.data[i][j] - bmats.Ax6064.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_21.data[i][j] + bmats.B_29_11.data[i][j] + bmats.B_5_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_29.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}