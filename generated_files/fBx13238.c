#include "fBx13238.h"

inline int fBx13238(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13238.data[i][j] = bmats.B_10_32.data[i][j] + bmats.B_11_32.data[i][j] + bmats.B_12_32.data[i][j] + bmats.B_13_32.data[i][j] + bmats.B_14_32.data[i][j] + bmats.B_1_32.data[i][j] + bmats.B_2_32.data[i][j] + bmats.B_3_32.data[i][j] + bmats.B_4_32.data[i][j] + bmats.B_5_32.data[i][j] + bmats.B_6_32.data[i][j] + bmats.B_7_32.data[i][j] + bmats.B_8_32.data[i][j] + bmats.B_9_32.data[i][j];
        }
    }
    return 0;
}
