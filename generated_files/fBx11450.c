#include "fBx11450.h"

inline int fBx11450(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11450.data[i][j] = bmats.B_22_5.data[i][j] + bmats.B_23_5.data[i][j] + bmats.B_24_5.data[i][j] + bmats.B_25_5.data[i][j] + bmats.B_26_5.data[i][j] + bmats.B_27_5.data[i][j] + bmats.B_29_5.data[i][j];
        }
    }
    return 0;
}
