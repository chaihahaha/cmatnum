#include "fBx13226.h"

inline int fBx13226(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13226.data[i][j] = bmats.B_10_31.data[i][j] + bmats.B_11_31.data[i][j] + bmats.B_12_31.data[i][j] + bmats.B_13_31.data[i][j] + bmats.B_15_31.data[i][j] + bmats.B_16_31.data[i][j] + bmats.B_1_31.data[i][j] + bmats.B_2_31.data[i][j] + bmats.B_3_31.data[i][j] + bmats.B_4_31.data[i][j] + bmats.B_5_31.data[i][j] + bmats.B_6_31.data[i][j] + bmats.B_7_31.data[i][j] + bmats.B_8_31.data[i][j] + bmats.B_9_31.data[i][j];
        }
    }
    return 0;
}
