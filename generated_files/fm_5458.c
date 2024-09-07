#include "fm_5458.h"

inline int fm_5458(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_3_1.data[i][j] - bmats.A_3_10.data[i][j] - bmats.A_3_11.data[i][j] - bmats.A_3_2.data[i][j] - bmats.A_3_3.data[i][j] - bmats.A_3_4.data[i][j] + 11*bmats.A_3_5.data[i][j] - bmats.A_3_6.data[i][j] - bmats.A_3_7.data[i][j] - bmats.A_3_8.data[i][j] - bmats.A_3_9.data[i][j] - bmats.A_5_1.data[i][j] - bmats.A_5_10.data[i][j] - bmats.A_5_11.data[i][j] - bmats.A_5_2.data[i][j] - bmats.A_5_3.data[i][j] - bmats.A_5_4.data[i][j] - bmats.A_5_5.data[i][j] - bmats.A_5_6.data[i][j] - bmats.A_5_7.data[i][j] - bmats.A_5_8.data[i][j] + 11*bmats.A_5_9.data[i][j] - bmats.A_9_1.data[i][j] - bmats.A_9_10.data[i][j] - bmats.A_9_11.data[i][j] - bmats.A_9_2.data[i][j] + 11*bmats.A_9_3.data[i][j] - bmats.A_9_4.data[i][j] - bmats.A_9_5.data[i][j] - bmats.A_9_6.data[i][j] - bmats.A_9_7.data[i][j] - bmats.A_9_8.data[i][j] - bmats.A_9_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_9_3.data[i][j]+bmats.B_3_5.data[i][j]+bmats.B_5_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
