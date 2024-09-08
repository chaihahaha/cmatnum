#include "fBx4096.h"

inline int fBx4096(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4096.data[i][j] = -bmats.B_10_21.data[i][j] + bmats.B_12_21.data[i][j] + bmats.B_13_21.data[i][j] + bmats.B_14_21.data[i][j] + bmats.B_15_21.data[i][j] + bmats.B_16_21.data[i][j] + bmats.B_17_21.data[i][j] + bmats.B_18_21.data[i][j] + bmats.B_19_21.data[i][j] + bmats.B_20_21.data[i][j] + bmats.B_21_21.data[i][j] + bmats.B_22_21.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_8_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx4092.data[i][j];
        }
    }
    return 0;
}
