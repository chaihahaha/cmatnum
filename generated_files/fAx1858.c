#include "fAx1858.h"

inline int fAx1858(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1858.data[i][j] = -bmats.A_12_1.data[i][j] - bmats.A_12_10.data[i][j] - bmats.A_12_11.data[i][j] - bmats.A_12_2.data[i][j] - bmats.A_12_4.data[i][j] - bmats.A_12_5.data[i][j] - bmats.A_12_6.data[i][j] - bmats.A_12_7.data[i][j] - bmats.A_12_9.data[i][j] + bmats.Ax1778.data[i][j];
        }
    }
    return 0;
}
