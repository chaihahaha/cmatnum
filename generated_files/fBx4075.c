#include "fBx4075.h"

inline int fBx4075(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4075.data[i][j] = -bmats.B_10_20.data[i][j] + bmats.B_12_20.data[i][j] + bmats.B_13_20.data[i][j] + bmats.B_14_20.data[i][j] + bmats.B_15_20.data[i][j] + bmats.B_16_20.data[i][j] + bmats.B_17_20.data[i][j] + bmats.B_18_20.data[i][j] + bmats.B_19_20.data[i][j] + bmats.B_20_20.data[i][j] + bmats.B_21_20.data[i][j] + bmats.B_22_20.data[i][j] - bmats.B_7_20.data[i][j] - bmats.B_8_20.data[i][j] - bmats.B_9_20.data[i][j] - bmats.Bx4071.data[i][j];
        }
    }
    return 0;
}
