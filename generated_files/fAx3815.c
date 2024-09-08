#include "fAx3815.h"

inline int fAx3815(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3815.data[i][j] = -10*bmats.A_1_1.data[i][j] + 2*bmats.A_1_10.data[i][j] + 2*bmats.A_1_11.data[i][j] + 2*bmats.A_1_2.data[i][j] + 2*bmats.A_1_3.data[i][j] + 2*bmats.A_1_4.data[i][j] + 2*bmats.A_1_5.data[i][j] + 2*bmats.A_1_6.data[i][j] + 2*bmats.A_1_7.data[i][j];
        }
    }
    return 0;
}
