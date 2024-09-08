#include "fBx2492.h"

inline int fBx2492(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2492.data[i][j] = bmats.B_20_29.data[i][j] + bmats.B_21_29.data[i][j] + bmats.B_22_29.data[i][j] + bmats.B_23_29.data[i][j] + bmats.B_24_29.data[i][j] + bmats.B_25_29.data[i][j] + bmats.B_26_29.data[i][j] + bmats.B_32_29.data[i][j];
        }
    }
    return 0;
}
