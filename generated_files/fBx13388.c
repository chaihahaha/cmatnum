#include "fBx13388.h"

inline int fBx13388(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13388.data[i][j] = bmats.B_10_15.data[i][j] + bmats.B_11_15.data[i][j] + bmats.B_13_15.data[i][j] + bmats.B_16_15.data[i][j] + bmats.B_1_15.data[i][j] + bmats.B_2_15.data[i][j] + bmats.B_3_15.data[i][j] + bmats.B_5_15.data[i][j] + bmats.B_6_15.data[i][j] + bmats.B_8_15.data[i][j] + bmats.B_9_15.data[i][j];
        }
    }
    return 0;
}