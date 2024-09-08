#include "fAx9.h"

inline int fAx9(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax9.data[i][j] = bmats.A_8_1.data[i][j] + bmats.A_8_10.data[i][j] + bmats.A_8_11.data[i][j] + bmats.A_8_2.data[i][j] + bmats.A_8_3.data[i][j] + bmats.A_8_4.data[i][j] + bmats.A_8_5.data[i][j] + bmats.A_8_8.data[i][j] + bmats.A_8_9.data[i][j];
        }
    }
    return 0;
}
