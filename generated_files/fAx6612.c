#include "fAx6612.h"

inline int fAx6612(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6612.data[i][j] = -bmats.A_17_18.data[i][j] - bmats.A_17_20.data[i][j] - bmats.A_17_23.data[i][j] - bmats.A_17_24.data[i][j] - bmats.A_17_25.data[i][j] - bmats.A_17_26.data[i][j] - bmats.A_17_27.data[i][j] - bmats.A_17_28.data[i][j];
        }
    }
    return 0;
}
