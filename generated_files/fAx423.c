#include "fAx423.h"

inline int fAx423(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax423.data[i][j] = -bmats.A_9_12.data[i][j] - bmats.A_9_13.data[i][j] - bmats.A_9_14.data[i][j] - bmats.A_9_15.data[i][j] - bmats.A_9_16.data[i][j] - bmats.A_9_17.data[i][j] - bmats.A_9_18.data[i][j] - bmats.A_9_19.data[i][j] - bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j];
        }
    }
    return 0;
}
