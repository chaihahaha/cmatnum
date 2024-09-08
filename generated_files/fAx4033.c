#include "fAx4033.h"

inline int fAx4033(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4033.data[i][j] = -bmats.A_22_1.data[i][j] - bmats.A_22_10.data[i][j] - bmats.A_22_11.data[i][j] - bmats.A_22_12.data[i][j] - bmats.A_22_13.data[i][j] - bmats.A_22_14.data[i][j] - bmats.A_22_15.data[i][j] - bmats.A_22_16.data[i][j] - bmats.A_22_2.data[i][j] - bmats.A_22_3.data[i][j] - bmats.A_22_4.data[i][j] - bmats.A_22_7.data[i][j] - bmats.A_22_8.data[i][j] - bmats.A_22_9.data[i][j] + bmats.Ax3867.data[i][j];
        }
    }
    return 0;
}
