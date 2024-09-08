#include "fm_2583.h"

inline int fm_2583(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_16_6.data[i][j] - bmats.A_16_7.data[i][j] - 11*bmats.A_17_12.data[i][j] + bmats.A_17_13.data[i][j] + bmats.A_17_14.data[i][j] + bmats.A_17_15.data[i][j] + bmats.A_17_16.data[i][j] + bmats.A_17_17.data[i][j] + bmats.A_17_18.data[i][j] + bmats.A_17_19.data[i][j] + bmats.A_17_20.data[i][j] + bmats.A_17_21.data[i][j] + bmats.A_17_22.data[i][j] - bmats.A_1_15.data[i][j] + 11*bmats.A_1_16.data[i][j] - bmats.Ax101.data[i][j] - bmats.Ax980.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_12_5.data[i][j] + bmats.B_16_17.data[i][j] + bmats.B_6_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_5_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
