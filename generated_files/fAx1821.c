#include "fAx1821.h"

inline int fAx1821(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1821.data[i][j] = -bmats.A_1_12.data[i][j] - bmats.A_1_13.data[i][j] - bmats.A_1_14.data[i][j] - bmats.A_1_15.data[i][j] - bmats.A_1_16.data[i][j] - bmats.A_1_17.data[i][j] - bmats.A_1_18.data[i][j] - bmats.A_1_19.data[i][j] - bmats.A_1_20.data[i][j] + bmats.Ax1763.data[i][j];
        }
    }
    return 0;
}
