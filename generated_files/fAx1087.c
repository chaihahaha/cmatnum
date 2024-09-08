#include "fAx1087.h"

inline int fAx1087(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1087.data[i][j] = -bmats.A_16_12.data[i][j] - bmats.A_16_13.data[i][j] - bmats.A_16_15.data[i][j] - bmats.A_16_17.data[i][j] - bmats.A_16_18.data[i][j] - bmats.A_16_19.data[i][j] - bmats.A_16_20.data[i][j] - bmats.A_16_21.data[i][j] - bmats.A_16_22.data[i][j];
        }
    }
    return 0;
}
