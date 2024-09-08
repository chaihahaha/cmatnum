#include "fAx1681.h"

inline int fAx1681(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1681.data[i][j] = -bmats.A_2_12.data[i][j] - bmats.A_2_13.data[i][j] - bmats.A_2_14.data[i][j] - bmats.A_2_15.data[i][j] - bmats.A_2_16.data[i][j] - bmats.A_2_17.data[i][j] - bmats.A_2_18.data[i][j] - bmats.A_2_21.data[i][j] - bmats.A_2_22.data[i][j] + bmats.Ax1597.data[i][j];
        }
    }
    return 0;
}
