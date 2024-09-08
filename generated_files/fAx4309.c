#include "fAx4309.h"

inline int fAx4309(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4309.data[i][j] = bmats.A_17_1.data[i][j] + bmats.A_17_10.data[i][j] + bmats.A_17_11.data[i][j] + bmats.A_17_12.data[i][j] + bmats.A_17_13.data[i][j] + bmats.A_17_14.data[i][j] + bmats.A_17_15.data[i][j] + bmats.A_17_16.data[i][j] + bmats.A_17_2.data[i][j] + bmats.A_17_5.data[i][j] + bmats.A_17_6.data[i][j] + bmats.A_17_7.data[i][j] + bmats.A_17_8.data[i][j] + bmats.A_17_9.data[i][j];
        }
    }
    return 0;
}
