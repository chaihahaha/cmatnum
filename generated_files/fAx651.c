#include "fAx651.h"

inline int fAx651(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax651.data[i][j] = -bmats.A_17_1.data[i][j] - bmats.A_17_10.data[i][j] - bmats.A_17_11.data[i][j] - bmats.A_17_2.data[i][j] - bmats.A_17_3.data[i][j] - bmats.A_17_4.data[i][j] - bmats.A_17_5.data[i][j] - bmats.A_17_6.data[i][j] - bmats.A_17_9.data[i][j] + bmats.Ax450.data[i][j];
        }
    }
    return 0;
}
