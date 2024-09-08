#include "fAx3034.h"

inline int fAx3034(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3034.data[i][j] = -bmats.A_15_14.data[i][j] - bmats.A_15_15.data[i][j] - bmats.A_15_16.data[i][j] - bmats.A_15_17.data[i][j] - bmats.A_15_18.data[i][j] - bmats.A_15_20.data[i][j] - bmats.A_15_21.data[i][j] - bmats.A_15_22.data[i][j];
        }
    }
    return 0;
}
