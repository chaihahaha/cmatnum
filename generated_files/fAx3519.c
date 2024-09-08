#include "fAx3519.h"

inline int fAx3519(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3519.data[i][j] = -bmats.A_24_1.data[i][j] - bmats.A_24_10.data[i][j] - bmats.A_24_11.data[i][j] - bmats.A_24_12.data[i][j] - bmats.A_24_15.data[i][j] - bmats.A_24_16.data[i][j] - bmats.A_24_2.data[i][j] - bmats.A_24_3.data[i][j] - bmats.A_24_4.data[i][j] - bmats.A_24_5.data[i][j] - bmats.A_24_6.data[i][j] - bmats.A_24_7.data[i][j] - bmats.A_24_8.data[i][j] - bmats.A_24_9.data[i][j] + bmats.Ax3450.data[i][j];
        }
    }
    return 0;
}
