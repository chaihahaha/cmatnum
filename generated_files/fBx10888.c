#include "fBx10888.h"

inline int fBx10888(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10888.data[i][j] = bmats.B_10_6.data[i][j] + bmats.B_11_6.data[i][j] + bmats.B_12_6.data[i][j] + bmats.B_13_6.data[i][j] + bmats.B_6_6.data[i][j] + bmats.B_7_6.data[i][j] + bmats.B_8_6.data[i][j] + bmats.B_9_6.data[i][j];
        }
    }
    return 0;
}
