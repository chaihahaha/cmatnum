#include "fm_4028.h"

inline int fm_4028(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_21.data[i][j] - bmats.A_18_22.data[i][j] + bmats.A_20_6.data[i][j] - 11*bmats.A_20_7.data[i][j] - bmats.Ax3246.data[i][j] - bmats.Ax648.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] + bmats.B_20_18.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_7_12.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_7_15.data[i][j] - bmats.B_7_16.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_7_18.data[i][j] - bmats.B_7_19.data[i][j] - bmats.B_7_20.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_7_22.data[i][j] - bmats.Bx4515.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_18.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
