#include "fBx13295.h"

inline int fBx13295(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13295.data[i][j] = bmats.B_17_26.data[i][j] + bmats.B_18_26.data[i][j] + bmats.B_19_26.data[i][j] + bmats.B_20_26.data[i][j] + bmats.B_21_26.data[i][j] + bmats.B_22_26.data[i][j] + bmats.B_23_26.data[i][j] + bmats.B_24_26.data[i][j] + bmats.B_25_26.data[i][j] + bmats.B_26_26.data[i][j] + bmats.B_27_26.data[i][j] + bmats.B_28_26.data[i][j] + bmats.B_29_26.data[i][j] + bmats.B_30_26.data[i][j] + bmats.B_31_26.data[i][j] + bmats.B_32_26.data[i][j] - bmats.Bx7184.data[i][j];
        }
    }
    return 0;
}
