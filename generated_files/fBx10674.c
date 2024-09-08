#include "fBx10674.h"

inline int fBx10674(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10674.data[i][j] = bmats.B_23_6.data[i][j] + bmats.B_24_6.data[i][j] + bmats.B_25_6.data[i][j] + bmats.B_26_6.data[i][j] + bmats.B_27_6.data[i][j] + bmats.B_28_6.data[i][j] + bmats.B_29_6.data[i][j] + bmats.B_30_6.data[i][j];
        }
    }
    return 0;
}
