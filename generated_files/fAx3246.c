#include "fAx3246.h"

inline int fAx3246(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3246.data[i][j] = -bmats.A_20_1.data[i][j] - bmats.A_20_10.data[i][j] - bmats.A_20_11.data[i][j] - bmats.A_20_2.data[i][j] - bmats.A_20_3.data[i][j] - bmats.A_20_4.data[i][j] - bmats.A_20_5.data[i][j] - bmats.A_20_8.data[i][j] - bmats.A_20_9.data[i][j] + bmats.Ax3166.data[i][j];
        }
    }
    return 0;
}
