#include "fAx1484.h"

inline int fAx1484(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1484.data[i][j] = bmats.A_30_1.data[i][j] + bmats.A_30_11.data[i][j] + bmats.A_30_12.data[i][j] + bmats.A_30_13.data[i][j] + bmats.A_30_14.data[i][j] + bmats.A_30_15.data[i][j] + bmats.A_30_16.data[i][j] + bmats.A_30_2.data[i][j] + bmats.A_30_3.data[i][j] + bmats.A_30_4.data[i][j] + bmats.A_30_5.data[i][j] + bmats.A_30_6.data[i][j] + bmats.A_30_7.data[i][j] + bmats.A_30_8.data[i][j];
        }
    }
    return 0;
}