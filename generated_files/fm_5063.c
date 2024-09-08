#include "fm_5063.h"

inline int fm_5063(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_16_21.data[i][j] - bmats.A_16_22.data[i][j] - bmats.A_19_15.data[i][j] + 11*bmats.A_19_16.data[i][j] + 11*bmats.A_21_19.data[i][j] - bmats.A_21_20.data[i][j] - bmats.Ax3146.data[i][j] - bmats.Ax828.data[i][j] - bmats.Ax848.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_16_21.data[i][j] + bmats.B_19_16.data[i][j] + bmats.B_21_19.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_19.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
