#include "fBx9722.h"

inline int fBx9722(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx9722.data[i][j] = bmats.B_24_10.data[i][j] + bmats.B_24_11.data[i][j] + bmats.B_24_12.data[i][j] + bmats.B_24_13.data[i][j] + bmats.B_24_14.data[i][j] + bmats.B_24_15.data[i][j] + bmats.B_24_16.data[i][j] + bmats.B_24_6.data[i][j] + bmats.B_24_7.data[i][j] + bmats.B_24_8.data[i][j] + bmats.B_24_9.data[i][j];
        }
    }
    return 0;
}
