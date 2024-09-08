#include "fAx935.h"

inline int fAx935(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax935.data[i][j] = bmats.A_13_1.data[i][j] + bmats.A_13_10.data[i][j] + bmats.A_13_11.data[i][j] + bmats.A_13_2.data[i][j] + bmats.A_13_3.data[i][j] + bmats.A_13_6.data[i][j] + bmats.A_13_7.data[i][j] + bmats.A_13_8.data[i][j] + bmats.A_13_9.data[i][j];
        }
    }
    return 0;
}
