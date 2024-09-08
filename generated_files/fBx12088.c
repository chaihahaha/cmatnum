#include "fBx12088.h"

inline int fBx12088(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12088.data[i][j] = bmats.B_17_20.data[i][j] + bmats.B_18_20.data[i][j] + bmats.B_19_20.data[i][j] + bmats.B_20_20.data[i][j] + bmats.B_21_20.data[i][j] + bmats.B_23_20.data[i][j] + bmats.B_24_20.data[i][j] + bmats.B_25_20.data[i][j] + bmats.B_26_20.data[i][j] + bmats.B_27_20.data[i][j] + bmats.B_31_20.data[i][j] + bmats.B_32_20.data[i][j];
        }
    }
    return 0;
}
