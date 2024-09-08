#include "fAx3288.h"

inline int fAx3288(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3288.data[i][j] = -bmats.A_19_1.data[i][j] - bmats.A_19_10.data[i][j] - bmats.A_19_11.data[i][j] - bmats.A_19_4.data[i][j] - bmats.A_19_5.data[i][j] - bmats.A_19_6.data[i][j] - bmats.A_19_7.data[i][j] - bmats.A_19_8.data[i][j] - bmats.A_19_9.data[i][j] + bmats.Ax3150.data[i][j];
        }
    }
    return 0;
}
