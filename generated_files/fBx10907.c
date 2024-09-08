#include "fBx10907.h"

inline int fBx10907(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10907.data[i][j] = bmats.B_10_22.data[i][j] + bmats.B_12_22.data[i][j] + bmats.B_13_22.data[i][j] + bmats.B_7_22.data[i][j] + bmats.B_8_22.data[i][j] + bmats.B_9_22.data[i][j];
        }
    }
    return 0;
}
