#include "fBx4118.h"

inline int fBx4118(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4118.data[i][j] = -bmats.B_10_22.data[i][j] - bmats.B_11_22.data[i][j] + bmats.B_12_22.data[i][j] + bmats.B_13_22.data[i][j] + bmats.B_14_22.data[i][j] + bmats.B_15_22.data[i][j] + bmats.B_16_22.data[i][j] + bmats.B_17_22.data[i][j] + bmats.B_18_22.data[i][j] + bmats.B_19_22.data[i][j] + bmats.B_20_22.data[i][j] + bmats.B_21_22.data[i][j] + bmats.B_22_22.data[i][j] - bmats.B_7_22.data[i][j] - bmats.B_8_22.data[i][j] - bmats.B_9_22.data[i][j] - bmats.Bx4114.data[i][j];
        }
    }
    return 0;
}
