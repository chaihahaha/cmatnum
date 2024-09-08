#include "fBx12662.h"

inline int fBx12662(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12662.data[i][j] = bmats.B_18_18.data[i][j] + bmats.B_19_18.data[i][j] + bmats.B_20_18.data[i][j] + bmats.B_23_18.data[i][j] + bmats.B_24_18.data[i][j] + bmats.B_25_18.data[i][j] + bmats.B_26_18.data[i][j] + bmats.B_27_18.data[i][j] + bmats.B_28_18.data[i][j] + bmats.B_29_18.data[i][j];
        }
    }
    return 0;
}
