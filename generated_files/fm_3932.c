#include "fm_3932.h"

inline int fm_3932(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_10_10.data[i][j] - bmats.A_10_11.data[i][j] - bmats.A_21_8.data[i][j] + 11*bmats.A_21_9.data[i][j] - bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j] - bmats.Ax2063.data[i][j] - bmats.Ax3077.data[i][j] - bmats.Ax329.data[i][j] - bmats.Ax547.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_20.data[i][j] - bmats.B_12_10.data[i][j] - bmats.B_13_10.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_15_10.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_17_10.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_19_10.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_22_10.data[i][j] - bmats.B_9_1.data[i][j] - bmats.B_9_10.data[i][j] - bmats.B_9_11.data[i][j] - bmats.B_9_2.data[i][j] - bmats.B_9_3.data[i][j] - bmats.B_9_4.data[i][j] - bmats.B_9_5.data[i][j] - bmats.B_9_6.data[i][j] - bmats.B_9_7.data[i][j] - bmats.B_9_8.data[i][j] - bmats.B_9_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_10_9.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
