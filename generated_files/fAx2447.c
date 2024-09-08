#include "fAx2447.h"

inline int fAx2447(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2447.data[i][j] = -bmats.A_5_1.data[i][j] - bmats.A_5_10.data[i][j] - bmats.A_5_11.data[i][j] - bmats.A_5_4.data[i][j] - bmats.A_5_6.data[i][j] - bmats.A_5_7.data[i][j] - bmats.A_5_8.data[i][j] - bmats.A_5_9.data[i][j];
        }
    }
    return 0;
}
