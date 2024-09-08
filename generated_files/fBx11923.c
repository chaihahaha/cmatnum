#include "fBx11923.h"

inline int fBx11923(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11923.data[i][j] = bmats.B_21_4.data[i][j] + bmats.B_22_4.data[i][j] + bmats.B_23_4.data[i][j] + bmats.B_24_4.data[i][j] + bmats.B_25_4.data[i][j] + bmats.B_26_4.data[i][j] + bmats.B_27_4.data[i][j] + bmats.B_28_4.data[i][j] + bmats.B_29_4.data[i][j] + bmats.B_30_4.data[i][j];
        }
    }
    return 0;
}
