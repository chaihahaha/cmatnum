#include "fBx13355.h"

inline int fBx13355(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13355.data[i][j] = bmats.B_11_16.data[i][j] + bmats.B_13_16.data[i][j] + bmats.B_14_16.data[i][j] + bmats.B_16_16.data[i][j] + bmats.B_4_16.data[i][j] + bmats.B_6_16.data[i][j] + bmats.B_7_16.data[i][j];
        }
    }
    return 0;
}
