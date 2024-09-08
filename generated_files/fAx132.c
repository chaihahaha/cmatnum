#include "fAx132.h"

inline int fAx132(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax132.data[i][j] = bmats.A_8_12.data[i][j] + bmats.A_8_13.data[i][j] + bmats.A_8_14.data[i][j] + bmats.A_8_15.data[i][j] + bmats.A_8_16.data[i][j] + bmats.A_8_19.data[i][j] + bmats.A_8_20.data[i][j] + bmats.A_8_21.data[i][j] + bmats.A_8_22.data[i][j];
        }
    }
    return 0;
}
