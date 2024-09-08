#include "fAx3206.h"

inline int fAx3206(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3206.data[i][j] = -bmats.A_21_1.data[i][j] - bmats.A_21_10.data[i][j] - bmats.A_21_2.data[i][j] - bmats.A_21_3.data[i][j] - bmats.A_21_4.data[i][j] - bmats.A_21_5.data[i][j] - bmats.A_21_6.data[i][j] - bmats.A_21_8.data[i][j] - bmats.A_21_9.data[i][j] + bmats.Ax3086.data[i][j];
        }
    }
    return 0;
}
