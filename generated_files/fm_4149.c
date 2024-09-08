#include "fm_4149.h"

inline int fm_4149(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_11.data[i][j] + bmats.A_8_2.data[i][j] - 11*bmats.A_8_3.data[i][j] + bmats.Ax1436.data[i][j] + bmats.Ax310.data[i][j] + bmats.Ax3150.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_19_3.data[i][j] - bmats.B_3_12.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_3_15.data[i][j] - bmats.B_3_16.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_3_18.data[i][j] - bmats.B_3_19.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_4_8.data[i][j] - bmats.B_5_8.data[i][j] - bmats.B_7_8.data[i][j] - bmats.B_9_8.data[i][j] - bmats.Bx4269.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
