#include "fBx11895.h"

inline int fBx11895(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11895.data[i][j] = bmats.B_20_20.data[i][j] + bmats.B_22_20.data[i][j] + bmats.B_24_20.data[i][j] + bmats.B_25_20.data[i][j] + bmats.B_26_20.data[i][j] + bmats.B_28_20.data[i][j] + bmats.B_30_20.data[i][j];
        }
    }
    return 0;
}
