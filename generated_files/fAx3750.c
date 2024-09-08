#include "fAx3750.h"

inline int fAx3750(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3750.data[i][j] = -bmats.A_23_1.data[i][j] - bmats.A_23_11.data[i][j] - bmats.A_23_12.data[i][j] - bmats.A_23_13.data[i][j] - bmats.A_23_14.data[i][j] - bmats.A_23_16.data[i][j] - bmats.A_23_2.data[i][j] - bmats.A_23_3.data[i][j] - bmats.A_23_4.data[i][j] - bmats.A_23_5.data[i][j] - bmats.A_23_6.data[i][j] - bmats.A_23_7.data[i][j] - bmats.A_23_8.data[i][j] - bmats.A_23_9.data[i][j] + bmats.Ax3713.data[i][j];
        }
    }
    return 0;
}
