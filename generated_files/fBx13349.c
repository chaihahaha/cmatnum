#include "fBx13349.h"

inline int fBx13349(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13349.data[i][j] = bmats.B_17_32.data[i][j] + bmats.B_18_32.data[i][j] + bmats.B_19_32.data[i][j] + bmats.B_20_32.data[i][j] + bmats.B_25_32.data[i][j] + bmats.B_26_32.data[i][j] + bmats.B_27_32.data[i][j] + bmats.B_28_32.data[i][j] + bmats.B_29_32.data[i][j];
        }
    }
    return 0;
}
