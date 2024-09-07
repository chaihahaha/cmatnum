#include "fm_2210.h"

inline int fm_2210(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_15_1.data[i][j] - bmats.A_15_10.data[i][j] - bmats.A_15_11.data[i][j] - bmats.A_15_2.data[i][j] - bmats.A_15_3.data[i][j] - bmats.A_15_4.data[i][j] - bmats.A_15_5.data[i][j] - bmats.A_15_6.data[i][j] - bmats.A_15_7.data[i][j] - bmats.A_15_8.data[i][j] + 11*bmats.A_15_9.data[i][j] + bmats.A_20_12.data[i][j] + bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] + bmats.A_20_15.data[i][j] + bmats.A_20_16.data[i][j] - 11*bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_19.data[i][j] + bmats.A_20_20.data[i][j] + bmats.A_20_21.data[i][j] + bmats.A_20_22.data[i][j] - bmats.A_6_12.data[i][j] - bmats.A_6_13.data[i][j] - bmats.A_6_14.data[i][j] + 11*bmats.A_6_15.data[i][j] - bmats.A_6_16.data[i][j] - bmats.A_6_17.data[i][j] - bmats.A_6_18.data[i][j] - bmats.A_6_19.data[i][j] - bmats.A_6_20.data[i][j] - bmats.A_6_21.data[i][j] - bmats.A_6_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_17_4.data[i][j]+bmats.B_9_17.data[i][j]+bmats.B_15_20.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_4_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
