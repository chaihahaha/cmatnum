#include "fBx4262.h"

inline int fBx4262(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4262.data[i][j] = bmats.B_12_18.data[i][j] + bmats.B_13_18.data[i][j] + bmats.B_14_18.data[i][j] + bmats.B_15_18.data[i][j] + bmats.B_16_18.data[i][j] + bmats.B_17_18.data[i][j] + bmats.B_18_18.data[i][j] + bmats.B_19_18.data[i][j] + bmats.B_20_18.data[i][j] + bmats.B_21_18.data[i][j] + bmats.B_22_18.data[i][j] - bmats.B_6_18.data[i][j] - bmats.Bx4260.data[i][j];
        }
    }
    return 0;
}
