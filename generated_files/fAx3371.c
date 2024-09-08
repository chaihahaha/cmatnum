#include "fAx3371.h"

inline int fAx3371(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3371.data[i][j] = -bmats.A_13_14.data[i][j] - bmats.A_13_15.data[i][j] - bmats.A_13_16.data[i][j] - bmats.A_13_17.data[i][j] - bmats.A_13_19.data[i][j] - bmats.A_13_20.data[i][j] - bmats.A_13_21.data[i][j] - bmats.A_13_22.data[i][j];
        }
    }
    return 0;
}
