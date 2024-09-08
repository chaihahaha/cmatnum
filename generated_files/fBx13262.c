#include "fBx13262.h"

inline int fBx13262(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13262.data[i][j] = bmats.B_12_5.data[i][j] + bmats.B_14_5.data[i][j] + bmats.B_15_5.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_19_5.data[i][j] - bmats.B_20_5.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_22_5.data[i][j] - bmats.B_23_5.data[i][j] - bmats.B_24_5.data[i][j] - bmats.B_25_5.data[i][j] - bmats.B_26_5.data[i][j] - bmats.B_27_5.data[i][j] - bmats.B_28_5.data[i][j] - bmats.B_29_5.data[i][j] - bmats.B_30_5.data[i][j] - bmats.B_31_5.data[i][j] - bmats.B_32_5.data[i][j] + bmats.B_4_5.data[i][j] + bmats.B_7_5.data[i][j] + bmats.B_9_5.data[i][j] + bmats.Bx11433.data[i][j];
        }
    }
    return 0;
}
