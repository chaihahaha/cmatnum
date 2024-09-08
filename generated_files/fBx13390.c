#include "fBx13390.h"

inline int fBx13390(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13390.data[i][j] = bmats.B_17_31.data[i][j] + bmats.B_25_31.data[i][j] + bmats.B_26_31.data[i][j] + bmats.B_27_31.data[i][j] + bmats.B_28_31.data[i][j] + bmats.B_29_31.data[i][j] + bmats.B_32_31.data[i][j];
        }
    }
    return 0;
}
