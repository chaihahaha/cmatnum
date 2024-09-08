#include "fAx6959.h"

inline int fAx6959(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6959.data[i][j] = -bmats.A_24_17.data[i][j] - bmats.A_24_19.data[i][j] - bmats.A_24_21.data[i][j] - bmats.A_24_29.data[i][j] - bmats.A_24_30.data[i][j] - bmats.A_24_31.data[i][j] - bmats.A_24_32.data[i][j];
        }
    }
    return 0;
}
