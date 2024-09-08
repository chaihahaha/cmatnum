#include "fAx477.h"

inline int fAx477(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax477.data[i][j] = -bmats.A_6_12.data[i][j] - bmats.A_6_13.data[i][j] - bmats.A_6_14.data[i][j] - bmats.A_6_15.data[i][j] - bmats.A_6_16.data[i][j] - bmats.A_6_17.data[i][j] - bmats.A_6_18.data[i][j] - bmats.A_6_19.data[i][j] - bmats.A_6_22.data[i][j] + bmats.Ax411.data[i][j];
        }
    }
    return 0;
}
