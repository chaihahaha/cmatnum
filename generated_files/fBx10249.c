#include "fBx10249.h"

inline int fBx10249(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10249.data[i][j] = bmats.B_10_7.data[i][j] + bmats.B_12_7.data[i][j] + bmats.B_2_7.data[i][j] + bmats.B_7_7.data[i][j] + bmats.B_8_7.data[i][j] + bmats.B_9_7.data[i][j];
        }
    }
    return 0;
}
