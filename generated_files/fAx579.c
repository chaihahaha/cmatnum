#include "fAx579.h"

inline int fAx579(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax579.data[i][j] = bmats.A_9_1.data[i][j] + bmats.A_9_10.data[i][j] + bmats.A_9_11.data[i][j] + bmats.A_9_12.data[i][j] + bmats.A_9_13.data[i][j] + bmats.A_9_14.data[i][j] + bmats.A_9_2.data[i][j] + bmats.A_9_3.data[i][j] + bmats.A_9_4.data[i][j] + bmats.A_9_5.data[i][j] + bmats.A_9_6.data[i][j] + bmats.A_9_7.data[i][j] + bmats.A_9_8.data[i][j] + bmats.A_9_9.data[i][j];
        }
    }
    return 0;
}
