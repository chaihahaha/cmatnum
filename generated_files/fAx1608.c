#include "fAx1608.h"

inline int fAx1608(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1608.data[i][j] = -bmats.A_20_1.data[i][j] - bmats.A_20_10.data[i][j] - bmats.A_20_11.data[i][j] - bmats.A_20_12.data[i][j] - bmats.A_20_13.data[i][j] - bmats.A_20_14.data[i][j] - bmats.A_20_16.data[i][j] - bmats.A_20_2.data[i][j] - bmats.A_20_3.data[i][j] - bmats.A_20_4.data[i][j] - bmats.A_20_5.data[i][j] - bmats.A_20_6.data[i][j] - bmats.A_20_7.data[i][j] - bmats.A_20_8.data[i][j] - bmats.A_20_9.data[i][j];
        }
    }
    return 0;
}
