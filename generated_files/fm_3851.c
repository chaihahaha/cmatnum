#include "fm_3851.h"

inline int fm_3851(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_11_17.data[i][j] - bmats.A_11_18.data[i][j] - bmats.A_17_10.data[i][j] - bmats.A_17_11.data[i][j] - bmats.A_22_21.data[i][j] + 11*bmats.A_22_22.data[i][j] - bmats.Ax141.data[i][j] - bmats.Ax3100.data[i][j] - bmats.Ax503.data[i][j] - bmats.Ax606.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_22.data[i][j] - bmats.B_11_22.data[i][j] - bmats.B_17_12.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_17_14.data[i][j] - bmats.B_17_15.data[i][j] - bmats.B_17_16.data[i][j] - bmats.B_17_17.data[i][j] - bmats.B_17_18.data[i][j] - bmats.B_17_19.data[i][j] - bmats.B_17_20.data[i][j] - bmats.B_17_21.data[i][j] - bmats.B_17_22.data[i][j] + bmats.B_22_6.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_9_22.data[i][j] - bmats.Bx4114.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
