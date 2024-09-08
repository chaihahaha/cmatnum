#include "fBx4272.h"

inline int fBx4272(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4272.data[i][j] = -bmats.B_12_8.data[i][j] - bmats.B_13_8.data[i][j] - bmats.B_14_8.data[i][j] - bmats.B_15_8.data[i][j] - bmats.B_16_8.data[i][j] - bmats.B_17_8.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_19_8.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_22_8.data[i][j] + bmats.B_4_8.data[i][j] + bmats.B_5_8.data[i][j] + bmats.B_7_8.data[i][j] + bmats.B_9_8.data[i][j] + bmats.Bx4269.data[i][j];
        }
    }
    return 0;
}
