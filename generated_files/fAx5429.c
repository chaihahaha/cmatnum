#include "fAx5429.h"

inline int fAx5429(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax5429.data[i][j] = -bmats.A_14_1.data[i][j] - bmats.A_14_10.data[i][j] - bmats.A_14_11.data[i][j] - bmats.A_14_12.data[i][j] - bmats.A_14_13.data[i][j] - bmats.A_14_15.data[i][j] - bmats.A_14_16.data[i][j] - bmats.A_14_2.data[i][j] - bmats.A_14_3.data[i][j] - bmats.A_14_4.data[i][j] - bmats.A_14_5.data[i][j] - bmats.A_14_6.data[i][j] - bmats.A_14_9.data[i][j];
        }
    }
    return 0;
}