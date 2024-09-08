#include "fBx4625.h"

inline int fBx4625(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4625.data[i][j] = bmats.B_17_28.data[i][j] + bmats.B_18_28.data[i][j] + bmats.B_19_28.data[i][j] + bmats.B_20_28.data[i][j] + bmats.B_21_28.data[i][j] + bmats.B_22_28.data[i][j] + bmats.B_23_28.data[i][j] + bmats.B_24_28.data[i][j] + bmats.B_25_28.data[i][j] + bmats.B_26_28.data[i][j] + bmats.B_27_28.data[i][j] + bmats.B_31_28.data[i][j] + bmats.B_32_28.data[i][j];
        }
    }
    return 0;
}
