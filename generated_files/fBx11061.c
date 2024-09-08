#include "fBx11061.h"

inline int fBx11061(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11061.data[i][j] = bmats.B_17_22.data[i][j] + bmats.B_18_22.data[i][j] + bmats.B_19_22.data[i][j] + bmats.B_20_22.data[i][j] + bmats.B_21_22.data[i][j] + bmats.B_22_22.data[i][j] + bmats.B_23_22.data[i][j] + bmats.B_26_22.data[i][j] + bmats.B_27_22.data[i][j] + bmats.B_30_22.data[i][j] + bmats.B_31_22.data[i][j] + bmats.B_32_22.data[i][j];
        }
    }
    return 0;
}
