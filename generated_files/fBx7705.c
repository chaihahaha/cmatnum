#include "fBx7705.h"

inline int fBx7705(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7705.data[i][j] = bmats.B_26_10.data[i][j] + bmats.B_26_11.data[i][j] + bmats.B_26_12.data[i][j] + bmats.B_26_13.data[i][j] + bmats.B_26_14.data[i][j] + bmats.B_26_15.data[i][j] + bmats.B_26_16.data[i][j] + bmats.B_26_8.data[i][j] + bmats.B_26_9.data[i][j];
        }
    }
    return 0;
}
