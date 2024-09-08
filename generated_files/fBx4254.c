#include "fBx4254.h"

inline int fBx4254(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4254.data[i][j] = -bmats.B_12_7.data[i][j] - bmats.B_13_7.data[i][j] - bmats.B_14_7.data[i][j] - bmats.B_15_7.data[i][j] - bmats.B_16_7.data[i][j] - bmats.B_17_7.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_19_7.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_22_7.data[i][j] + bmats.B_5_7.data[i][j] + bmats.B_6_7.data[i][j] + bmats.B_7_7.data[i][j] + bmats.B_9_7.data[i][j] + bmats.Bx4249.data[i][j];
        }
    }
    return 0;
}
