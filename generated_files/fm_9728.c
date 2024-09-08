#include "fm_9728.h"

inline int fm_9728(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_24_15.data[i][j] - bmats.A_24_16.data[i][j] - bmats.A_24_31.data[i][j] - bmats.A_24_32.data[i][j] - bmats.Ax621.data[i][j] - bmats.Ax697.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = -bmats.Bx10449.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_16.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
