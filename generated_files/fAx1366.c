#include "fAx1366.h"

inline int fAx1366(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1366.data[i][j] = bmats.A_9_12.data[i][j] + bmats.A_9_15.data[i][j] + bmats.A_9_16.data[i][j] + bmats.A_9_17.data[i][j] + bmats.A_9_18.data[i][j] + bmats.A_9_19.data[i][j] + bmats.A_9_20.data[i][j] + bmats.A_9_21.data[i][j] + bmats.A_9_22.data[i][j];
        }
    }
    return 0;
}
