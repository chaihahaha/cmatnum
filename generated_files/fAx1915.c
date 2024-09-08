#include "fAx1915.h"

inline int fAx1915(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1915.data[i][j] = -bmats.A_1_1.data[i][j] - bmats.A_1_2.data[i][j] - bmats.A_1_3.data[i][j] - bmats.A_1_4.data[i][j] - bmats.A_1_5.data[i][j] - bmats.A_1_6.data[i][j] - bmats.A_1_7.data[i][j] - bmats.A_1_8.data[i][j] - bmats.A_1_9.data[i][j];
        }
    }
    return 0;
}
