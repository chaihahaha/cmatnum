#include "fBx13289.h"

inline int fBx13289(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13289.data[i][j] = bmats.B_17_25.data[i][j] + bmats.B_18_25.data[i][j] + bmats.B_19_25.data[i][j] + bmats.B_20_25.data[i][j] + bmats.B_21_25.data[i][j] + bmats.B_22_25.data[i][j] + bmats.B_23_25.data[i][j] + bmats.B_24_25.data[i][j] + bmats.B_25_25.data[i][j] + bmats.B_26_25.data[i][j] + bmats.B_27_25.data[i][j] + bmats.B_28_25.data[i][j] + bmats.B_29_25.data[i][j] + bmats.B_30_25.data[i][j] + bmats.B_31_25.data[i][j] + bmats.B_32_25.data[i][j] - bmats.Bx8279.data[i][j];
        }
    }
    return 0;
}
