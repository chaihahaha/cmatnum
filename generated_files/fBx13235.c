#include "fBx13235.h"

inline int fBx13235(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13235.data[i][j] = bmats.B_10_16.data[i][j] + bmats.B_12_16.data[i][j] - bmats.B_17_16.data[i][j] - bmats.B_18_16.data[i][j] - bmats.B_19_16.data[i][j] + bmats.B_1_16.data[i][j] - bmats.B_20_16.data[i][j] - bmats.B_21_16.data[i][j] - bmats.B_22_16.data[i][j] - bmats.B_23_16.data[i][j] - bmats.B_24_16.data[i][j] - bmats.B_25_16.data[i][j] - bmats.B_26_16.data[i][j] - bmats.B_27_16.data[i][j] - bmats.B_28_16.data[i][j] - bmats.B_29_16.data[i][j] - bmats.B_30_16.data[i][j] - bmats.B_31_16.data[i][j] - bmats.B_32_16.data[i][j] + bmats.B_8_16.data[i][j] + bmats.B_9_16.data[i][j] + bmats.Bx13230.data[i][j];
        }
    }
    return 0;
}