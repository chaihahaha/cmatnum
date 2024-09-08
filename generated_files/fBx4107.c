#include "fBx4107.h"

inline int fBx4107(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4107.data[i][j] = bmats.B_10_11.data[i][j] + bmats.B_11_11.data[i][j] - bmats.B_12_11.data[i][j] - bmats.B_13_11.data[i][j] - bmats.B_14_11.data[i][j] - bmats.B_15_11.data[i][j] - bmats.B_16_11.data[i][j] - bmats.B_17_11.data[i][j] - bmats.B_18_11.data[i][j] - bmats.B_19_11.data[i][j] + bmats.B_1_11.data[i][j] - bmats.B_20_11.data[i][j] - bmats.B_21_11.data[i][j] - bmats.B_22_11.data[i][j] + bmats.B_2_11.data[i][j] + bmats.B_3_11.data[i][j] + bmats.B_4_11.data[i][j] + bmats.B_5_11.data[i][j] + bmats.B_6_11.data[i][j] + bmats.B_7_11.data[i][j] + bmats.B_8_11.data[i][j] + bmats.B_9_11.data[i][j];
        }
    }
    return 0;
}
