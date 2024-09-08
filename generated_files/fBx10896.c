#include "fBx10896.h"

inline int fBx10896(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10896.data[i][j] = bmats.B_22_22.data[i][j] + bmats.B_24_22.data[i][j] + bmats.B_25_22.data[i][j] + bmats.B_26_22.data[i][j] + bmats.B_27_22.data[i][j] + bmats.B_28_22.data[i][j] + bmats.B_29_22.data[i][j];
        }
    }
    return 0;
}
