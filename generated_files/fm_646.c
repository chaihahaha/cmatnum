#include "fm_646.h"

inline int fm_646(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_11.data[i][j] - bmats.A_11_12.data[i][j] - bmats.A_13_31.data[i][j] - bmats.A_13_32.data[i][j] + 16*bmats.A_27_13.data[i][j] - bmats.A_27_14.data[i][j] + 16*bmats.A_3_11.data[i][j] - bmats.A_3_12.data[i][j] - bmats.Ax2190.data[i][j] - bmats.Ax2208.data[i][j] - bmats.Ax2558.data[i][j] - bmats.Ax488.data[i][j] - bmats.Ax760.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_29.data[i][j] - bmats.B_13_11.data[i][j] - bmats.B_13_12.data[i][j] - bmats.B_13_14.data[i][j] - bmats.B_13_15.data[i][j] - bmats.B_13_16.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_13_5.data[i][j] - bmats.Bx4615.data[i][j] - bmats.Bx5970.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_13_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}