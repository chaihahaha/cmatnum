#include "fAx3291.h"

inline int fAx3291(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3291.data[i][j] = -bmats.A_9_17.data[i][j] - bmats.A_9_18.data[i][j] - bmats.A_9_19.data[i][j] - bmats.A_9_20.data[i][j] - bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j] - bmats.A_9_23.data[i][j] - bmats.A_9_24.data[i][j] - bmats.A_9_27.data[i][j] - bmats.A_9_28.data[i][j] - bmats.A_9_29.data[i][j] - bmats.A_9_30.data[i][j] - bmats.A_9_31.data[i][j] - bmats.A_9_32.data[i][j] + bmats.Ax3157.data[i][j];
        }
    }
    return 0;
}