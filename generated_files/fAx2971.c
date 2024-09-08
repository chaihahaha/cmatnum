#include "fAx2971.h"

inline int fAx2971(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2971.data[i][j] = -bmats.A_26_1.data[i][j] - bmats.A_26_11.data[i][j] - bmats.A_26_12.data[i][j] - bmats.A_26_13.data[i][j] - bmats.A_26_14.data[i][j] - bmats.A_26_16.data[i][j] - bmats.A_26_2.data[i][j] - bmats.A_26_3.data[i][j] - bmats.A_26_4.data[i][j] - bmats.A_26_5.data[i][j] - bmats.A_26_6.data[i][j] - bmats.A_26_7.data[i][j] - bmats.A_26_8.data[i][j] - bmats.A_26_9.data[i][j] + bmats.Ax2874.data[i][j];
        }
    }
    return 0;
}
