#include "fBx12151.h"

inline int fBx12151(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12151.data[i][j] = bmats.B_24_1.data[i][j] + bmats.B_24_15.data[i][j] + bmats.B_24_16.data[i][j] + bmats.B_24_2.data[i][j] + bmats.B_24_3.data[i][j] + bmats.B_24_4.data[i][j] + bmats.B_24_5.data[i][j] + bmats.B_24_6.data[i][j] + bmats.B_24_7.data[i][j] + bmats.B_24_8.data[i][j];
        }
    }
    return 0;
}
