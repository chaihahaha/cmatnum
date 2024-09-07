#include "fm_1172.h"

inline int fm_1172(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_11_1.data[i][j] + bmats.A_11_10.data[i][j] + bmats.A_11_11.data[i][j] + bmats.A_11_2.data[i][j] + bmats.A_11_3.data[i][j] + bmats.A_11_4.data[i][j] + bmats.A_11_5.data[i][j] - 11*bmats.A_11_6.data[i][j] + bmats.A_11_7.data[i][j] + bmats.A_11_8.data[i][j] + bmats.A_11_9.data[i][j] - bmats.A_17_1.data[i][j] - bmats.A_17_10.data[i][j] - bmats.A_17_11.data[i][j] - bmats.A_17_2.data[i][j] - bmats.A_17_3.data[i][j] + 11*bmats.A_17_4.data[i][j] - bmats.A_17_5.data[i][j] - bmats.A_17_6.data[i][j] - bmats.A_17_7.data[i][j] - bmats.A_17_8.data[i][j] - bmats.A_17_9.data[i][j] - bmats.A_4_12.data[i][j] - bmats.A_4_13.data[i][j] - bmats.A_4_14.data[i][j] - bmats.A_4_15.data[i][j] - bmats.A_4_16.data[i][j] - bmats.A_4_17.data[i][j] - bmats.A_4_18.data[i][j] - bmats.A_4_19.data[i][j] - bmats.A_4_20.data[i][j] - bmats.A_4_21.data[i][j] + 11*bmats.A_4_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_22_6.data[i][j]+bmats.B_4_11.data[i][j]+bmats.B_6_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
