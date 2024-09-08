#include "fBx9994.h"

inline int fBx9994(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx9994.data[i][j] = bmats.B_23_23.data[i][j] + bmats.B_24_23.data[i][j] + bmats.B_25_23.data[i][j] + bmats.B_27_23.data[i][j] + bmats.B_28_23.data[i][j] + bmats.B_29_23.data[i][j];
        }
    }
    return 0;
}
