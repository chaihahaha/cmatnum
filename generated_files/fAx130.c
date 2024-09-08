#include "fAx130.h"

inline int fAx130(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax130.data[i][j] = -11*bmats.A_7_1.data[i][j] + bmats.A_7_10.data[i][j] + bmats.A_7_11.data[i][j] + bmats.A_7_2.data[i][j] + bmats.A_7_3.data[i][j] + bmats.A_7_4.data[i][j] + bmats.A_7_5.data[i][j] + bmats.A_7_6.data[i][j] + bmats.A_7_7.data[i][j] + bmats.A_7_8.data[i][j] + bmats.A_7_9.data[i][j];
        }
    }
    return 0;
}
