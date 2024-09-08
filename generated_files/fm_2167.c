#include "fm_2167.h"

inline int fm_2167(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_18_8.data[i][j] + 11*bmats.A_18_9.data[i][j] + bmats.A_20_12.data[i][j] + bmats.A_20_13.data[i][j] - 11*bmats.A_20_14.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_20.data[i][j] - bmats.A_3_17.data[i][j] + 11*bmats.A_3_18.data[i][j] - bmats.Ax144.data[i][j] - bmats.Ax2242.data[i][j] - bmats.Ax2715.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_7.data[i][j] + bmats.B_18_20.data[i][j] + bmats.B_9_14.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_7_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
