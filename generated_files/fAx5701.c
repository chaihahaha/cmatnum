#include "fAx5701.h"

inline int fAx5701(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax5701.data[i][j] = -bmats.A_13_1.data[i][j] - bmats.A_13_10.data[i][j] - bmats.A_13_11.data[i][j] - bmats.A_13_12.data[i][j] - bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] - bmats.A_13_15.data[i][j] - bmats.A_13_16.data[i][j] - bmats.A_13_2.data[i][j] - bmats.A_13_5.data[i][j] - bmats.A_13_6.data[i][j] - bmats.A_13_7.data[i][j] - bmats.A_13_8.data[i][j] - bmats.A_13_9.data[i][j];
        }
    }
    return 0;
}