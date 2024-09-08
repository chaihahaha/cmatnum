#include "fAx3420.h"

inline int fAx3420(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3420.data[i][j] = -bmats.A_12_14.data[i][j] - bmats.A_12_15.data[i][j] - bmats.A_12_17.data[i][j] - bmats.A_12_19.data[i][j] - bmats.A_12_20.data[i][j] - bmats.A_12_21.data[i][j];
        }
    }
    return 0;
}
