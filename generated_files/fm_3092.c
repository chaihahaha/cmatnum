#include "fm_3092.h"

inline int fm_3092(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_19_8.data[i][j] + 11*bmats.A_19_9.data[i][j] - bmats.Ax2181.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_19_20.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_8_20.data[i][j]+=12 * m.data[i][j];
        bmats.C_12_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_19.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
