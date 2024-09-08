#include "fAx3424.h"

inline int fAx3424(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3424.data[i][j] = bmats.A_16_17.data[i][j] + bmats.A_16_18.data[i][j] + bmats.A_16_19.data[i][j] + bmats.A_16_20.data[i][j] + bmats.A_16_21.data[i][j] + bmats.A_16_22.data[i][j] + bmats.A_16_25.data[i][j] + bmats.A_16_26.data[i][j] + bmats.A_16_27.data[i][j] + bmats.A_16_28.data[i][j] + bmats.A_16_29.data[i][j] + bmats.A_16_30.data[i][j] + bmats.A_16_31.data[i][j] + bmats.A_16_32.data[i][j];
        }
    }
    return 0;
}
