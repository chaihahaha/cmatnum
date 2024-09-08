#include "fm_5172.h"

inline int fm_5172(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 10*bmats.A_14_19.data[i][j] - 2*bmats.A_14_20.data[i][j] - bmats.A_19_13.data[i][j] + 11*bmats.A_19_14.data[i][j] - bmats.Ax1455.data[i][j] - bmats.Ax3767.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_14.data[i][j] + bmats.B_14_19.data[i][j] + bmats.B_19_14.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_14.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
