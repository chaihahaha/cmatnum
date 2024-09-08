#include "fAx3598.h"

inline int fAx3598(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3598.data[i][j] = bmats.A_8_17.data[i][j] + bmats.A_8_18.data[i][j] + bmats.A_8_21.data[i][j] + bmats.A_8_22.data[i][j] + bmats.A_8_23.data[i][j] + bmats.A_8_24.data[i][j] + bmats.A_8_25.data[i][j] + bmats.A_8_26.data[i][j] + bmats.A_8_27.data[i][j] + bmats.A_8_28.data[i][j] + bmats.A_8_29.data[i][j] + bmats.A_8_30.data[i][j] + bmats.A_8_31.data[i][j] + bmats.A_8_32.data[i][j];
        }
    }
    return 0;
}
