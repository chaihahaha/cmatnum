#include "fAx1031.h"

inline int fAx1031(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1031.data[i][j] = -bmats.A_5_12.data[i][j] - bmats.A_5_13.data[i][j] - bmats.A_5_14.data[i][j] - bmats.A_5_15.data[i][j] - bmats.A_5_16.data[i][j] - bmats.A_5_17.data[i][j] - bmats.A_5_18.data[i][j] - bmats.A_5_21.data[i][j] - bmats.A_5_22.data[i][j] + bmats.Ax949.data[i][j];
        }
    }
    return 0;
}
