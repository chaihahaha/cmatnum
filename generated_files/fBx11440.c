#include "fBx11440.h"

inline int fBx11440(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11440.data[i][j] = bmats.B_10_21.data[i][j] + bmats.B_11_21.data[i][j] + bmats.B_12_21.data[i][j] + bmats.B_13_21.data[i][j] + bmats.B_14_21.data[i][j] + bmats.B_6_21.data[i][j] + bmats.B_8_21.data[i][j];
        }
    }
    return 0;
}
