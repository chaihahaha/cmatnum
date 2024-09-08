#include "fAx3308.h"

inline int fAx3308(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3308.data[i][j] = -bmats.A_18_1.data[i][j] - bmats.A_18_10.data[i][j] - bmats.A_18_11.data[i][j] - bmats.A_18_2.data[i][j] - bmats.A_18_3.data[i][j] - bmats.A_18_4.data[i][j] - bmats.A_18_7.data[i][j] - bmats.A_18_8.data[i][j] - bmats.A_18_9.data[i][j] + bmats.Ax164.data[i][j];
        }
    }
    return 0;
}
