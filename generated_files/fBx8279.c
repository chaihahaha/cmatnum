#include "fBx8279.h"

inline int fBx8279(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx8279.data[i][j] = bmats.B_10_25.data[i][j] + bmats.B_11_25.data[i][j] + bmats.B_12_25.data[i][j] + bmats.B_13_25.data[i][j] + bmats.B_14_25.data[i][j] + bmats.B_15_25.data[i][j] + bmats.B_16_25.data[i][j] + bmats.B_1_25.data[i][j] + bmats.B_2_25.data[i][j] + bmats.B_3_25.data[i][j] + bmats.B_4_25.data[i][j] + bmats.B_5_25.data[i][j] + bmats.B_6_25.data[i][j] + bmats.B_7_25.data[i][j] + bmats.B_8_25.data[i][j] + bmats.B_9_25.data[i][j];
        }
    }
    return 0;
}