#include "fAx1332.h"

inline int fAx1332(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1332.data[i][j] = -bmats.A_4_13.data[i][j] - bmats.A_4_14.data[i][j] - bmats.A_4_15.data[i][j] - bmats.A_4_16.data[i][j] - bmats.A_4_18.data[i][j] - bmats.A_4_19.data[i][j] - bmats.A_4_20.data[i][j] - bmats.A_4_21.data[i][j] - bmats.A_4_22.data[i][j] + bmats.Ax1239.data[i][j];
        }
    }
    return 0;
}
