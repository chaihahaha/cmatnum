#include "fBx3115.h"

inline int fBx3115(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx3115.data[i][j] = bmats.B_14_1.data[i][j] + bmats.B_14_10.data[i][j] + bmats.B_14_11.data[i][j] + bmats.B_14_13.data[i][j] + bmats.B_14_14.data[i][j] + bmats.B_14_15.data[i][j] + bmats.B_14_16.data[i][j] + bmats.B_14_2.data[i][j] + bmats.B_14_5.data[i][j];
        }
    }
    return 0;
}
