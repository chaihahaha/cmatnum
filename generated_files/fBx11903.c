#include "fBx11903.h"

inline int fBx11903(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11903.data[i][j] = bmats.B_10_4.data[i][j] + bmats.B_11_4.data[i][j] + bmats.B_12_4.data[i][j] + bmats.B_4_4.data[i][j] + bmats.B_7_4.data[i][j] + bmats.B_8_4.data[i][j];
        }
    }
    return 0;
}
