#include "fAx7543.h"

inline int fAx7543(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7543.data[i][j] = -bmats.A_29_21.data[i][j] - bmats.A_29_22.data[i][j] - bmats.A_29_23.data[i][j] - bmats.A_29_24.data[i][j] - bmats.A_29_25.data[i][j] - bmats.A_29_26.data[i][j] - bmats.A_29_27.data[i][j] - bmats.A_29_28.data[i][j] - bmats.A_29_30.data[i][j];
        }
    }
    return 0;
}
