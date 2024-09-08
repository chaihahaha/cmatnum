#include "fAx3150.h"

inline int fAx3150(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3150.data[i][j] = -11*bmats.A_10_19.data[i][j] + bmats.A_10_20.data[i][j] - 11*bmats.A_11_19.data[i][j] + bmats.A_11_20.data[i][j] - 11*bmats.A_1_19.data[i][j] + bmats.A_1_20.data[i][j] - 11*bmats.A_2_19.data[i][j] + bmats.A_2_20.data[i][j] - 11*bmats.A_3_19.data[i][j] + bmats.A_3_20.data[i][j] - 11*bmats.A_4_19.data[i][j] + bmats.A_4_20.data[i][j] - 11*bmats.A_5_19.data[i][j] + bmats.A_5_20.data[i][j] - 11*bmats.A_6_19.data[i][j] + bmats.A_6_20.data[i][j] - 11*bmats.A_7_19.data[i][j] + bmats.A_7_20.data[i][j] - 11*bmats.A_8_19.data[i][j] + bmats.A_8_20.data[i][j] - 11*bmats.A_9_19.data[i][j] + bmats.A_9_20.data[i][j] + bmats.Ax1023.data[i][j] + bmats.Ax1279.data[i][j] + bmats.Ax1476.data[i][j] + bmats.Ax1673.data[i][j] + bmats.Ax1851.data[i][j] + bmats.Ax1985.data[i][j] + bmats.Ax1988.data[i][j] + bmats.Ax1991.data[i][j] + bmats.Ax1994.data[i][j] + bmats.Ax1997.data[i][j] + bmats.Ax357.data[i][j];
        }
    }
    return 0;
}
