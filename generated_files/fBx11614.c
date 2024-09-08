#include "fBx11614.h"

inline int fBx11614(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11614.data[i][j] = bmats.B_21_21.data[i][j] + bmats.B_23_21.data[i][j] + bmats.B_24_21.data[i][j] + bmats.B_25_21.data[i][j] + bmats.B_26_21.data[i][j] + bmats.B_29_21.data[i][j] + bmats.B_30_21.data[i][j];
        }
    }
    return 0;
}
