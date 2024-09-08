#include "fBx12409.h"

inline int fBx12409(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12409.data[i][j] = bmats.B_19_19.data[i][j] + bmats.B_21_19.data[i][j] + bmats.B_22_19.data[i][j] + bmats.B_25_19.data[i][j] + bmats.B_28_19.data[i][j] + bmats.B_29_19.data[i][j] + bmats.B_31_19.data[i][j];
        }
    }
    return 0;
}
