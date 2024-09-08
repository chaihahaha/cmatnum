#include "fBx12111.h"

inline int fBx12111(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12111.data[i][j] = bmats.B_10_20.data[i][j] + bmats.B_11_20.data[i][j] + bmats.B_12_20.data[i][j] + bmats.B_14_20.data[i][j] + bmats.B_5_20.data[i][j] + bmats.B_7_20.data[i][j] + bmats.B_8_20.data[i][j] + bmats.B_9_20.data[i][j];
        }
    }
    return 0;
}
