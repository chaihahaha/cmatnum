#include "fBx10008.h"

inline int fBx10008(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10008.data[i][j] = bmats.B_24_7.data[i][j] + bmats.B_25_7.data[i][j] + bmats.B_26_7.data[i][j] + bmats.B_27_7.data[i][j] + bmats.B_28_7.data[i][j] + bmats.B_29_7.data[i][j] + bmats.B_30_7.data[i][j];
        }
    }
    return 0;
}
