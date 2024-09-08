#include "fAx3382.h"

inline int fAx3382(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3382.data[i][j] = -bmats.A_13_17.data[i][j] - bmats.A_13_18.data[i][j] - bmats.A_13_19.data[i][j] - bmats.A_13_20.data[i][j] - bmats.A_13_21.data[i][j] + 11*bmats.A_13_22.data[i][j];
        }
    }
    return 0;
}
