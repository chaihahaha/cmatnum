#include "fm_84.h"

inline int fm_84(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_10.data[i][j] - bmats.A_15_11.data[i][j] + 11*bmats.A_17_17.data[i][j] - bmats.A_17_18.data[i][j] + 11*bmats.A_6_15.data[i][j] - bmats.A_6_16.data[i][j] - bmats.Ax384.data[i][j] - bmats.Ax70.data[i][j] - bmats.Ax736.data[i][j] - bmats.Ax738.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = -bmats.B_10_17.data[i][j] - bmats.B_11_17.data[i][j] - bmats.B_15_12.data[i][j] - bmats.B_15_13.data[i][j] - bmats.B_15_14.data[i][j] - bmats.B_15_15.data[i][j] - bmats.B_15_16.data[i][j] - bmats.B_15_17.data[i][j] - bmats.B_15_18.data[i][j] - bmats.B_15_19.data[i][j] - bmats.B_15_20.data[i][j] - bmats.B_15_21.data[i][j] - bmats.B_15_22.data[i][j] + bmats.B_17_4.data[i][j] - bmats.B_1_17.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_4_17.data[i][j] - bmats.B_5_17.data[i][j] - bmats.B_6_17.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_8_17.data[i][j] - bmats.B_9_17.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_15.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
