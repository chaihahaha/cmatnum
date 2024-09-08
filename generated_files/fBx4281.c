#include "fBx4281.h"

inline int fBx4281(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4281.data[i][j] = bmats.B_12_19.data[i][j] + bmats.B_13_19.data[i][j] + bmats.B_14_19.data[i][j] + bmats.B_15_19.data[i][j] + bmats.B_16_19.data[i][j] + bmats.B_17_19.data[i][j] + bmats.B_18_19.data[i][j] + bmats.B_19_19.data[i][j] + bmats.B_20_19.data[i][j] + bmats.B_21_19.data[i][j] + bmats.B_22_19.data[i][j] - bmats.B_7_19.data[i][j] - bmats.B_8_19.data[i][j] - bmats.Bx4278.data[i][j];
        }
    }
    return 0;
}
