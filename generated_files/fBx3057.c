#include "fBx3057.h"

inline int fBx3057(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx3057.data[i][j] = bmats.B_29_11.data[i][j] + bmats.B_29_12.data[i][j] + bmats.B_29_13.data[i][j] + bmats.B_29_14.data[i][j] + bmats.B_29_15.data[i][j] + bmats.B_29_16.data[i][j];
        }
    }
    return 0;
}
