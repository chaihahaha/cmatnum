#include "fBx13259.h"

inline int fBx13259(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13259.data[i][j] = -bmats.B_15_20.data[i][j] - bmats.B_16_20.data[i][j] + bmats.B_17_20.data[i][j] + bmats.B_18_20.data[i][j] + bmats.B_19_20.data[i][j] - bmats.B_1_20.data[i][j] + bmats.B_20_20.data[i][j] + bmats.B_21_20.data[i][j] + bmats.B_22_20.data[i][j] + bmats.B_23_20.data[i][j] + bmats.B_24_20.data[i][j] + bmats.B_25_20.data[i][j] + bmats.B_26_20.data[i][j] + bmats.B_27_20.data[i][j] + bmats.B_28_20.data[i][j] + bmats.B_29_20.data[i][j] - bmats.B_2_20.data[i][j] + bmats.B_30_20.data[i][j] + bmats.B_31_20.data[i][j] + bmats.B_32_20.data[i][j] - bmats.B_3_20.data[i][j] - bmats.B_4_20.data[i][j] - bmats.B_9_20.data[i][j] - bmats.Bx11916.data[i][j];
        }
    }
    return 0;
}
