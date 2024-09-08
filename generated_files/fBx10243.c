#include "fBx10243.h"

inline int fBx10243(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10243.data[i][j] = bmats.B_10_23.data[i][j] + bmats.B_11_23.data[i][j] + bmats.B_14_23.data[i][j] + bmats.B_7_23.data[i][j] + bmats.B_8_23.data[i][j] + bmats.B_9_23.data[i][j];
        }
    }
    return 0;
}
