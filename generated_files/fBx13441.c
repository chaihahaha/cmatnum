#include "fBx13441.h"

inline int fBx13441(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13441.data[i][j] = bmats.B_18_32.data[i][j] + bmats.B_19_32.data[i][j] + bmats.B_20_32.data[i][j] + bmats.B_21_32.data[i][j] + bmats.B_22_32.data[i][j] + bmats.B_23_32.data[i][j] + bmats.B_24_32.data[i][j] + bmats.B_26_32.data[i][j] + bmats.B_27_32.data[i][j] + bmats.B_29_32.data[i][j] + bmats.B_30_32.data[i][j] + bmats.B_31_32.data[i][j] + bmats.B_32_32.data[i][j];
        }
    }
    return 0;
}
