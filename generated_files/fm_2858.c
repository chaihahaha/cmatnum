#include "fm_2858.h"

inline int fm_2858(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.Ax949.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.Bx4231.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_16_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
