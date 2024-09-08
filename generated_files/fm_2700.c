#include "fm_2700.h"

inline int fm_2700(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_14_4.data[i][j] + 11*bmats.A_14_5.data[i][j] + bmats.A_16_16.data[i][j] - 11*bmats.A_16_17.data[i][j] + bmats.A_16_18.data[i][j] + bmats.A_16_19.data[i][j] - bmats.A_6_13.data[i][j] + 11*bmats.A_6_14.data[i][j] - bmats.Ax2988.data[i][j] - bmats.Ax714.data[i][j] - bmats.Ax938.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_16.data[i][j] + bmats.B_17_3.data[i][j] + bmats.B_5_17.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_3_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
