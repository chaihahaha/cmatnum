#include "fBx12142.h"

inline int fBx12142(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12142.data[i][j] = bmats.B_10_20.data[i][j] + bmats.B_13_20.data[i][j] + bmats.B_14_20.data[i][j] + bmats.B_15_20.data[i][j] + bmats.B_16_20.data[i][j] + bmats.B_1_20.data[i][j] + bmats.B_2_20.data[i][j] + bmats.B_3_20.data[i][j] + bmats.B_4_20.data[i][j] + bmats.B_5_20.data[i][j] + bmats.B_6_20.data[i][j] + bmats.B_7_20.data[i][j] + bmats.B_8_20.data[i][j] + bmats.B_9_20.data[i][j];
        }
    }
    return 0;
}
