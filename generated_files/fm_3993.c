#include "fm_3993.h"

inline int fm_3993(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_20_9.data[i][j] + bmats.A_9_8.data[i][j] - 11*bmats.A_9_9.data[i][j] + bmats.Ax3132.data[i][j] + bmats.Ax3166.data[i][j] + bmats.Ax462.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_9.data[i][j] - bmats.B_11_9.data[i][j] + bmats.B_20_9.data[i][j] - bmats.B_5_9.data[i][j] - bmats.B_7_9.data[i][j] - bmats.B_8_9.data[i][j] - bmats.B_9_12.data[i][j] - bmats.B_9_13.data[i][j] - bmats.B_9_14.data[i][j] - bmats.B_9_15.data[i][j] - bmats.B_9_16.data[i][j] - bmats.B_9_17.data[i][j] - bmats.B_9_18.data[i][j] - bmats.B_9_19.data[i][j] - bmats.B_9_20.data[i][j] - bmats.B_9_21.data[i][j] - bmats.B_9_22.data[i][j] - bmats.Bx4289.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
