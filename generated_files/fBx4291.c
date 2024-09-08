#include "fBx4291.h"

inline int fBx4291(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4291.data[i][j] = bmats.B_10_9.data[i][j] + bmats.B_11_9.data[i][j] - bmats.B_12_9.data[i][j] - bmats.B_13_9.data[i][j] - bmats.B_14_9.data[i][j] - bmats.B_15_9.data[i][j] - bmats.B_16_9.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_9.data[i][j] + bmats.B_5_9.data[i][j] + bmats.B_7_9.data[i][j] + bmats.B_8_9.data[i][j] + bmats.Bx4289.data[i][j];
        }
    }
    return 0;
}
