#include "fm_3828.h"

inline int fm_3828(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_11_8.data[i][j] - 11*bmats.A_11_9.data[i][j] - bmats.A_20_9.data[i][j] + bmats.Ax3102.data[i][j] + bmats.Ax3128.data[i][j] + bmats.Ax462.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_11.data[i][j] - bmats.B_11_11.data[i][j] - bmats.B_1_11.data[i][j] + bmats.B_22_9.data[i][j] - bmats.B_2_11.data[i][j] - bmats.B_3_11.data[i][j] - bmats.B_4_11.data[i][j] - bmats.B_5_11.data[i][j] - bmats.B_6_11.data[i][j] - bmats.B_7_11.data[i][j] - bmats.B_8_11.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_12.data[i][j] - bmats.B_9_13.data[i][j] - bmats.B_9_14.data[i][j] - bmats.B_9_15.data[i][j] - bmats.B_9_16.data[i][j] - bmats.B_9_17.data[i][j] - bmats.B_9_18.data[i][j] - bmats.B_9_19.data[i][j] - bmats.B_9_20.data[i][j] - bmats.B_9_21.data[i][j] - bmats.B_9_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
