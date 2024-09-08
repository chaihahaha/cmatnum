#include "fBx3105.h"

inline int fBx3105(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx3105.data[i][j] = bmats.B_14_3.data[i][j] + bmats.B_14_4.data[i][j] + bmats.B_14_6.data[i][j] + bmats.B_14_7.data[i][j] + bmats.B_14_8.data[i][j] + bmats.B_14_9.data[i][j];
        }
    }
    return 0;
}
