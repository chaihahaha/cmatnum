#include "fBx13228.h"

inline int fBx13228(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13228.data[i][j] = -bmats.B_14_31.data[i][j] + bmats.B_17_31.data[i][j] + bmats.B_18_31.data[i][j] + bmats.B_19_31.data[i][j] + bmats.B_20_31.data[i][j] + bmats.B_21_31.data[i][j] + bmats.B_22_31.data[i][j] + bmats.B_23_31.data[i][j] + bmats.B_24_31.data[i][j] + bmats.B_25_31.data[i][j] + bmats.B_26_31.data[i][j] + bmats.B_27_31.data[i][j] + bmats.B_28_31.data[i][j] + bmats.B_29_31.data[i][j] + bmats.B_30_31.data[i][j] + bmats.B_31_31.data[i][j] + bmats.B_32_31.data[i][j] - bmats.Bx13226.data[i][j];
        }
    }
    return 0;
}
