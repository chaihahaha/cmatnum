#include "fAx8027.h"

inline int fAx8027(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8027.data[i][j] = -bmats.A_30_17.data[i][j] - bmats.A_30_19.data[i][j] - bmats.A_30_20.data[i][j] - bmats.A_30_23.data[i][j] - bmats.A_30_24.data[i][j] - bmats.A_30_25.data[i][j] - bmats.A_30_26.data[i][j];
        }
    }
    return 0;
}
